#include<bits/stdc++.h>
#include<iostream>

#define Max 100010

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
#define FIO  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define CS(i) cout<<"Case :"<<i<<"\n";

using namespace std;



int T[4*Max+4];
int hight[Max];
int arr[Max];


int n;


///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = hight[l];
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = max(T[2 * id] ,T[2 * id + 1]);
}

void update(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = -11111;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid);
	else
		update(p, 2 * id + 1, mid, r);
	T[id] = max(T[2 * id] , T[2 * id + 1]);
}




int ask(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return l;
	int mid = (l + r)/2;
	int p1=ask(x, y, id * 2, l, mid);
	int p2=ask(x, y, id*2+1, mid, r);
}

int query(l,r)
{
    return ask(l,r+1,1,1,n+1);
}




int main()
{
    int tc;
    scani(tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        scani(n);
        for(int i=1; i<=n ;i++)
        {
            scani(arr[i]);
            scani(hight[i]);
        }
        bulid(1,1,n+1);


        int rem=n;

        while(1)
        {
            if(rem==0)
                break;

            for(int i=1; i<)

        }



    }



    return 0;
}

