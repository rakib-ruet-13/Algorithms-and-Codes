#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int tc;
    ll n;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        scanf("%lld",&n);

        ll res=0;

        ll s=sqrt(n);

        for(ll i=1; i<=s ; i++)
        {
            res= res + (n/i) + i*(n/i - n/(i+1));

        }

            if(n/s==s)
                res-=s;


        printf("Case %d: %lld\n",cs,res);


    }

    return 0;
}
