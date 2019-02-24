#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x);
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)
#define mem(x,val) memset(x,val,sizeof(x))
#define Max 50001


 struct node
    {
        int val;
        int pos;
    };


bool comp(node a,node b)
{
    return a.val< b.val;
}

int main()
{
    ll n,m;

    cin>>n;

    node arr[1000];

    memset(arr,0,sizeof(arr));

    ll sum =0;

    for(int i=0; i<n;i++)
    {
        cin>>m;
        arr[i].pos=i+1;
        arr[i].val=m;

    }

    sort(arr,arr+n,comp);



    for(int i=0; i<=n/2-1 ; i++)
    {
       cout<<arr[i].pos<<" "<<arr[n-i-1].pos<<endl;
    }






    return 0;
}

