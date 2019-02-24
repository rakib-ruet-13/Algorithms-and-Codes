#include<iostream>
#include<bits/stdc++.h>
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
#define FIO  ios_base::sync_with_stdio(false)
#define CS(i) cout<<"Case :"<<i<<"\n";

using namespace std;

int T[4*Max+4];


int n;
int arr[Max];

///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = arr[l];
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = min(T[2 * id],T[2 * id + 1]);
}

void update(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = 0;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid);
	else
		update(p, 2 * id + 1, mid, r);
	T[id] =min(T[2 * id], T[2 * id + 1]);
}




int ask(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 1000000;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return T[id];
	int mid = (l + r)/2;
	return min(ask(x, y, id * 2, l, mid),ask(x, y, id*2+1, mid, r));
}






int main()
{

    int tc;
    scani(tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n,q;
        scani(n);
        scani(q);

        for(int i=0 ;i<=n ;i++)
            arr[i]=1111111;

        for(int i=1; i<=n ;i++)
            scani(arr[i]);

        build(1,0,n+1);

        printf("Case %d:\n",cs);
        while(q--)
        {
            int p,q;
            scani(p);
            scani(q);

            if(p>q)
                swap(p,q);

            printf("%d\n",ask(p,q+1,1,0,n+1));
        }


    }



    return 0;
}

