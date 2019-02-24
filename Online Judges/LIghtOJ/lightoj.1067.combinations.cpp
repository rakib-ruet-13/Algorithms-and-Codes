#include<iostream>
#include<bits/stdc++.h>
#define MAX  1000000
#define mod 1000003

using namespace std;

typedef long long ll;

long long fact_n[MAX+1];
long long inverse[MAX+1];


void gen_fact()
{
    long long val=1;
    fact_n[0]=1;

    for(int i=1;i<=MAX;i++)
    {
        val= ((val%mod)*(i%mod))%mod;
        fact_n[i]=val;

    }

}

long long pow_mod(ll n,ll p)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll temp=pow_mod(n,p/2);
        return ( (temp%mod) * (temp%mod))%mod;
    }
    else
    {
        return ((n%mod)*pow_mod(n,p-1))%mod;
    }
}

long long mod_inverse(ll n)
{
    //cout<<pow_mod(n,mod-2)<<endl;
    return pow_mod(n,mod-2);

}

void gen_mod_inverse()
{

    for(int i=0;i<=MAX;i++)
    {

        inverse[i]=mod_inverse(fact_n[i]);
    }
}


long long nCr(long long n,long long r)
{

    return ((((fact_n[n]%mod)*inverse[n-r])%mod)*inverse[r])%mod;

}

int main()
{
    gen_fact();
    gen_mod_inverse();

    int tc, n,r;

    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {

        scanf("%d %d",&n,&r);
        printf("Case %d: %lld\n",cs,nCr(n,r));

    }

   return 0;

}

