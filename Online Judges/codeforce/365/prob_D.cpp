/********************************************************/
/********************************************************/
/*************          RAKIB         *******************/
/************       CSE 13, RUET       ******************/
/***********          contact:           ****************/
/******     mail: rakib_cse13@outlook.com     ***********/
/*****           mobile : 01846207019           *********/
/********************************************************/
/********************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/******macros****/

#define Max 1000005
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid (x>=1 && x<=row && y>=1 && y<=col)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define pii pair<ll,ll>

/***** useful function ****/

ll power(ll base, ll p){ ll ans=1;if(p==0)return 1;for(ll i=1;i<=p;i++)ans*=base;return ans;}
ll gcd(ll a, ll b){if(a==0)return b;gcd(b,a%b);}


/***** Nececessary global variables ****/
ll row,col;
int arr[Max];
int tree[Max*4];

ll ans=0;

void init(int n,int start,int end)
{


    if(start==end)
    {
        tree[n]=arr[start];
        return ;
    }

    init(2*n,start,(start+end)/2);
    init(2*n+1,(start+end)/2+1,end);

    tree[n]=tree[2*n]^tree[2*n+1];
}

ll query(int n,int start,int end,int rs,int re)
{

    if(end<rs || start>re)
        return ans=ans+0;

    if(start>=rs && end<=re)
    {
        return ans=ans^tree[n];
    }
    query(2*n, start, (start+end)/2,rs,re);
    query(2*n+1,(start+end)/2+1,end,rs,re);


    return ans;

}
void update(int n,int start,int end,int index,int val)
{
    if(end<index || start>index)
        return;
    if(start==index && end==index)
    {
        tree[n]=arr[index]=val;
        return;
    }
     update(2*n, start, (start+end)/2,index,val);
     update(2*n+1,(start+end)/2+1,end,index,val);

     tree[n]=tree[2*n]^tree[2*n+1];
}


int main()
{
     int n;
     cin>>n;

     for(int i=1;i<=n;i++)
       cin>>arr[i];

     init(1,1,n);

     int p;
     cin>>p;

     for(int k=1;k<=p;k++)

        {
            int q1,q2;

            cin>>q1>>q2;

            cout<<query(1,1,n,q1,q2)<<endl;;




        }







     return 0;


}






