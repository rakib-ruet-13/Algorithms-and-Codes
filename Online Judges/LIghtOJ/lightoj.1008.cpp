#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b ;i++)
#define pb push_back
#define read64(x) scanf("%lld",&x)
#define read32(x) scanf("%d",&x)
#define ll long long
#define mod 1e9+7
#define pi acos(-1.000)
#define Max 1010

using namespace std;


int main()
{
    int tc;
    read32(tc);
    ll ans,n,r;


    rep(cs,1,tc)
    {
        read64(n);

        r=ceil((double)(sqrt((double)n)));
        ans=r*r-r+1;

        long long x,y;

        if(ans<n)
        {
            x=r;
            y=r-(n-ans);
        }
        else
        {
            y=r;
            x=r-(ans-n);
        }


        if(r%2==1)
        printf("Case %d: %lld %lld\n",cs,y,x);
        else
        {
              printf("Case %d: %lld %lld\n",cs,x,y);
        }

    }

    return 0;
}
