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

    rep(cs,1,tc)
    {
        ll c,n;
        read64(n);
        read64(c);

        ll t=0;
        ll pre=0;
        ll val=0;

        for( t=0 ; c > (t*n) && n!=0 ; t++)
        {
            if(t*(c-t*n) > pre)
            {
                pre=c-t*n;
                val=t;
            }
        }

        printf("Case %d: %lld\n",cs,val);
    }
}

