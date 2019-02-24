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
#define FIO  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define CS(i) cout<<"Case :"<<i<<"\n";
#define mod 1000000007
using namespace std;





int T[4*Max+4];

int  n;

///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = 0;
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = (T[2 * id] + T[2 * id + 1])%mod;
}

void update(int p,int val,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = val%mod;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, val,2 * id, l, mid);
	else
		update(p,val, 2 * id + 1, mid, r);
	T[id] = (T[2 * id] + T[2 * id + 1])%mod;
}




int ask(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return T[id]%mod;
	int mid = (l + r)/2;
	return (ask(x, y, id * 2, l, mid) +ask(x, y, id*2+1, mid, r))%mod;
}


struct node
{
    int ind;
    int val;

};


bool comp(node a, node b)
{
    if(a.val==b.val)
        return a.ind>b.ind;
    return a.val<b.val;
}

int main()
{

    int tc;
    node arr[Max];

    scani(tc);

    rep(cs,1,tc)
    {
        int n;
        scani(n);
        build(1,0,n+1);

        for(int i=0; i<n ;i++)
        {
            int temp;
            scani(temp);

            arr[i].val=temp;
            arr[i].ind=i+1;
        }

        sort(arr,arr+n,comp);


        for(int i=0; i<n ;i++)
        {
            int id=arr[i].ind;
            int temp=ask(1,id,1,0,n+1);

            temp++;
            update(id,temp,1,0,n+1);
        }

        int ans=ask(1,n+1,1,0,n+1);





        printf("Case %d: %d\n",cs,ans);
    }




    return 0;
}

