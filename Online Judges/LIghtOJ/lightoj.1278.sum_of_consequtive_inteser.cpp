#include<iostream>
#include<bits/stdc++.h>
#define Max 10000100
#define pb(x) push_back(x)
#define ll long long

using namespace std;


bool sieve[Max+1];
vector <int> prime;

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
        {

             prime.pb(i);
        }

    }

}


long long divisor(ll n)
{

    if(n==1)
        return 1;

    if(n<Max)
    {
        if(sieve[n]==0)
             return 2;

    }


    ll ans=1;

    int i=0;

    while( n>1 && i<prime.size() && prime[i]<=sqrt(n))
    {
         if(n<Max)
        {
           if(sieve[n]==0)
            return ans*2;
        }

        int cnt=0;

        while(n%prime[i]==0)
        {
            n=n/prime[i];
            cnt++;
        }

        if(cnt>0)
            ans*=(cnt+1);

            i++;
    }

    if(n!=1)
    {
       ans*=2;
    }
    return ans;
}


int main()
{
   int tc;
   long long n;
   Gen_prime();

     scanf("%d",&tc);

      for(int cs=1 ; cs<=tc ;cs++ )
      {
          scanf("%lld",&n);

          while(n%2==0)
            n=n/2;
          printf("Case %d: %lld\n",cs, divisor(n)-1);
      }



}
