#include<bits/stdc++.h>
#include<iostream>

#define Max 724728

#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define sz size()
#define scan(a) scanf("%lld",&a);
#define scani(a) scanf("%d",&a);
#define printa(a) printf("%lld\n",a);
#define printi(a) printf("%d\n",a);
#define uu first
#define vv second
#define FIO  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define CS(i) cout<<"Case :"<<i<<"\n";

using namespace std;



int T[4*Max+4];


int n;

///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = 1;
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];
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
	T[id] = T[2 * id] + T[2 * id + 1];
}


/***** ask with no need of binary search *****/

int ask(int id = 1,int l = 1,int r = n+1,int sum=0){// [x, y)
    if(r - l < 2){
		return l;
	}


    if(T[id]>=sum)
    {
        int mid=(l+r)/2;

        if(T[id*2]>=sum)
          ask(id*2,l,mid,sum);
        else
          ask(id*2+1,mid,r,sum-T[id*2]);
    }
    else
        return 11111111;

}




int get_index(int k)
{
    int p=ask(1,1,Max+2,k);
    return p;
}



int main()
{

    int tc;
    scani(tc);

    int arr[100001];

    rep(cs,1,tc)
    {
        int n;
        scani(n);
        build(1,1,Max+2);

        for(int i=n ; i>=1 ; i--)
        {
            scani(arr[i]);
        }


        int last=n;

        for(int i=1 ;i<n ; i++)
        {
           int p=last-arr[i];
           int ind=get_index(p);
           update(ind,1,1,Max+2);
           last--;
        }
        printf("Case %d: %d\n",cs,get_index(1));

    }
    return 0;
}




