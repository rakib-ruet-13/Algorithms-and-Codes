#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define pb(x) push_back(x)
#define mod (1e9+7)ll
#define pi acos(-1.0000)
#define pii pair<long long,long long>
#define VI vector<long long>
#define CLEAR(a)  memset(a,0,sizeof(a))
#define ALL(x) (x.begin(),x.end())
#define pis pair<int,string>
#define mp make_pair
#define Max 100010
#define mem(x,val) memset(x,val,sizeof(x))
#define iread(a) scanf("%d",&a)
#define llread(b) scanf("%lld",&b)
#define dread(d) scanf("%lf",&d)

using namespace std;

typedef long long ll;

ll arr1[1001];
ll arr2[1001];
ll arr3[1001];

int main()
{
    int n;

    cin>>n;

    ll mx1,mx2;
    mx1=-111111;
    rep(i,0,n-1)
    {
      cin>>arr1[i];
      if(i!=0)
        arr1[i]=arr1[i]|arr1[i-1];
    }



     rep(i,0,n-1)
    {
      cin>>arr2[i];
      if(i!=0)
        arr2[i]=arr2[i]|arr2[i-1];
    }

    mx2=-111111;
      rep(i,0,n-1)
    {
        mx2=max(arr1[i]+arr2[i],mx2);
    }



    cout<<mx2<<endl;


    return 0;
}
