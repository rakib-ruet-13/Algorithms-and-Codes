#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define pi acos(-1.0000)
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define ll long long
#define pb(x) push_back(x)
#define rep(i,x) for(int k=i;k<=x;k++)
#define uu  first
#define vv second
#define vaild(x,y) (x>=1 && x<=row && y>=1 && y<=row)

long long gcd(ll a,ll b)
{
    if(a==0)
        return b;
    else
        return (b,a%b);
}

long long ncr(ll n,ll r)
{
    ll ans=1;
    ll div=1;
    ll s;


    for(int i=1;i<=r;i++)
    {
        ans*=(n-i+1);
        div=div*i;

        s=gcd(ans,div);

        if(s>1)
        {
            ans=ans/s;
            div=div/s;
        }
    }

    return ans;

}

int main()
{

    int tc;
    int arr[12],i;
    memset(arr,0,sizeof(arr));
    vector<int>vct;

    int n,m;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr[num]++;
    }

    for(i=0;i<12;i++)
    {
       // cout<<arr[i]<<endl;
        if(arr[i]>0)
            vct.push_back(arr[i]);

    }
    sort(vct.begin(),vct.end());

    //cout<<vct.size()<<endl;;

    ll ans=0;

    for( i=0;i<vct.size();i++)
    {
        for(int j=i+1;j<vct.size();j++)
        {
            //cout<<vct[i]<<" "<<vct[j]<<endl;
            ans+=vct[i]*vct[j];

        }
    }

    cout<<ans<<endl;


    return 0;
}
