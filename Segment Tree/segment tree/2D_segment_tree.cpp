#include<iostream>
#include<bits/stdc++.h>
#define Max 1010

#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define sz size()
#define scan(a) scanf("%lld",&a);
#define scani(a) scanf("%d",&a);
#define print(a) printf("%lld\n",a);
#define printi(a) printf("%d\n",a);
#define uu first
#define vv second

/****[L,R] formate with 1 index row,col ***/

using namespace std;

int row,col;
int t[4*Max+4][4*Max+4];
int a[Max+4][Max+4];



void build_y (int id_x, int lx, int rx, int id_y, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			t[id_x][id_y] = a[lx][ly];
		else
			t[id_x][id_y] = t[id_x*2][id_y] + t[id_x*2+1][id_y];
	else {
		int mid = (ly + ry) / 2;
		build_y (id_x, lx, rx, id_y*2, ly, mid);
		build_y (id_x, lx, rx, id_y*2+1, mid+1, ry);
		t[id_x][id_y] = t[id_x][id_y*2] + t[id_x][id_y*2+1];
	}
}


void build_x (int idx, int lx, int rx) {
	if (lx != rx) {
		int mid = (lx + rx) / 2;
		build_x (idx*2, lx, mid);
		build_x (idx*2+1, mid+1, rx);
	}
	build_y (idx, lx, rx, 1, 1, col);
}







int sum_y (int id_x, int id_y, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;

	if (ly == tly && try_ == ry)
		return t[id_x][id_y];

	int tmy = (tly + try_) / 2;
	return sum_y (id_x, id_y*2, tly, tmy, ly, min(ry,tmy))
		+ sum_y (id_x, id_y*2+1, tmy+1, try_, max(ly,tmy+1), ry);
}


int sum_x (int id_x, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;

	if(lx>trx || tlx>ly)
        return 0;

	if (lx <= tlx && trx <= rx)
		return sum_y (id_x, 1, 1,col, ly, ry);

	int mid = (tlx + trx) / 2;

	return sum_x (id_x*2, tlx, mid, lx, min(rx,mid), ly, ry)
		+ sum_x (id_x*2+1, mid+1, trx, max(lx,mid+1), rx, ly, ry);
}





void update_y (int id_x, int lx, int rx, int id_y, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[id_x][id_y] = new_val;
		else
			t[id_x][id_y] = t[id_x*2][id_y] + t[id_x*2+1][id_y];
	}
	else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y (id_x, lx, rx, id_y*2, ly, my, x, y, new_val);
		else
			update_y (id_x, lx, rx, id_y*2+1, my+1, ry, x, y, new_val);
		t[id_x][id_y] = t[id_x][id_y*2] + t[id_x][id_y*2+1];
	}
}

void update_x (int id_x, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x (id_x*2, lx, mx, x, y, new_val);
		else
			update_x (id_x*2+1, mx+1, rx, x, y, new_val);
	}
	update_y (id_x, lx, rx, 1, 1, col, x, y, new_val);
}


int main()
{




    return 0;
}
