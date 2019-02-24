#include<iostream>
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define Max 10000100

using namespace std;
typedef long long ll;

bool sieve[Max+1];
vector<int>prime;


void Gen_prime()
{
    for(int i=4; i<=Max;i+=2)
        sieve[i]=1;
    for(int i=3; i<=sqrt(Max);i+=2)
    {
        if(!sieve[i])
            for(int j=i*i ;j<=Max;j+=2*i)
                sieve[j]=1;
    }
    prime.pb(2);
    for(int i=3 ;i<=Max ;i+=2)
    {
        if(!sieve[i])
            prime.pb(i);
    }

}

ll divisor(ll n)
{
    if(n==1)
        return 1;
    if(n<Max)
        if(!sieve[n])
         {

              return 3;

         }


    int i=0;

    ll ans;
    ans=1;
    int cnt;

    while(prime[i]<=sqrt(n) && i<prime.size() && n>1)
    {

        if(n<Max)
        if(!sieve[n])
        {

            return ans*(3);
        }

       cnt=0;
       while(n%prime[i]==0)
       {
           n=n/prime[i];
           cnt++;
       }
       if(cnt>0)
       {
           ans*=(2*cnt+1);
       }


        i++;
    }

    if(n!=1)
        {
            return ans*3;

        }
    return ans;
}

int main()
{

    Gen_prime();
    long long n,ans;
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc; cs++)
    {
        scanf("%lld",&n);
        ans=divisor(n)+1;
        printf("Case %d: %lld\n",cs,ans/2);
    }



}
