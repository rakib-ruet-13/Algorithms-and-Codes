#include<iostream>
#include<bits/stdc++.h>



using namespace std;

typedef long long  ll;

ll mod;

long long pow_mod(long long n,long long p)
{
    if(p==0)
        return 1;
    if(p%2==1)
    {
        return ((n%mod)*pow_mod(n,p-1))%mod;

    }

    ll temp=pow_mod(n,p/2);
    return (temp*temp)%mod;
}





int main()
{
    int tc;
    ll n,k,sum;

    scanf("%d",&tc);

    for(int cs=1; cs<=tc; cs++)
    {
        scanf("%lld %lld %lld",&n,&k,&mod);

        sum=0;

        ll val;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&val);
            sum+=val;
            sum=sum%mod;
        }

        sum= (((((pow_mod(n,k-1))*(k%mod))%mod)%mod)*sum)%mod;


        printf("Case %d: %lld\n",cs,sum);
    }


    return 0;
}
