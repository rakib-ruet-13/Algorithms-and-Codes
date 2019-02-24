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
    scanf("%d",&tc);

    rep(cs,1,tc)
    {
        ll n,d;
        scanf("%lld",&n);

        d=1;

         while(n%2==0)
        {
            d=d*2;
            n=n/2;
        }

        if(d==1)
            printf("Case %d: Impossible\n",cs);
        else
            printf("Case %d: %lld %lld\n",cs,n,d);

    }

    return 0;


    return 0;
}


