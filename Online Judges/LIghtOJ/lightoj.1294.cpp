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
        ll n,k;
        read64(n);
        read64(k);

        printf("Case %d: %lld\n",cs,(n/2)*k);
    }

    return 0;


}
