#include<iostream>
#include<bits/stdc++.h>
#define Max 1000100



using namespace std;

typedef long long ll;

long long pow_mod(long long n,long long p);
void gen_prime();
long long power(long long base,long long p);
ll Ext_euclid(ll a,ll b);
ll mod_inverse(ll n);


long long mod=1000000007;

long long  x,y;

bool sieve[Max+1];
vector<int>vct;



long long divisors_sum(long long n,long long p)
{

    long long res=1;

    if(p==0)
        return 1;

    int s=vct.size();


    int i=0;

    while(n>1 && i<s && vct[i]<=sqrt(n))
          {

            int cnt=0;

            if(1 && n>1 && n<Max)
            {




                if(sieve[n]==0)
                {

                     ll ans1=mod_inverse(n-1);
                     ll ans2=(mod+pow_mod(n,p+1)-1)%mod;

                     res*=(((ans1%mod)*(ans2%mod))%mod)%mod;



                    return res=res%mod;

                }

            }

            if(n%vct[i]==0)
            {
                while(n%vct[i]==0)
                {
                    n=n/vct[i];
                    cnt++;
                }

                ll temp=vct[i];

                 ll ans1=mod_inverse(temp-1);
                 ll ans2=(mod+pow_mod(temp,p*cnt+1)-1)%mod;

                 res*=((ans1%mod)*(ans2%mod))%mod;
                 res=res%mod;
            }

           i++;



          }
          if(n!=1)
          {


               ll ans1=mod_inverse(n-1);
               ll ans2=(mod+pow_mod(n,p+1)-1)%mod;

                res*=(((ans1%mod)*(ans2%mod))%mod)%mod;



               res=res%mod;
          }


          res=(mod+res)%mod;
          return res;
}


int main()
{
     long long n,p;

     gen_prime();

     int tc;

     scanf("%d",&tc);

     for(int cs=1;cs<=tc;cs++)
     {
         scanf("%lld %lld",&n,&p);

         printf("Case %d: %lld\n",cs,divisors_sum(n,p));

     }
     return 0;


}





void gen_prime()
{

    int s=sqrt(Max);

    for(int i=4;i<=Max;i+=2)
        sieve[i]=1;

    for(int i=3;i<=s;i+=2)
    {
        if(!sieve[i])
        {
            for(int j=i*i;j<=Max;j+=2*i)
                sieve[j]=1;
        }
    }
    vct.push_back(2);

    for(int i=3;i<=Max;i+=2)
    {
        if(sieve[i]==0)
            vct.push_back(i);
    }


}

long long pow_mod(long long n,long long p)
{
    if(p==0)
     return 1;

    if(p==1)
        return n%mod;

    else if(p%2==0)
    {
        long long temp=pow_mod(n,p/2);

        return (temp*temp)%mod;
    }
    else
    {
        return ((n%mod)*pow_mod(n,p-1))%mod;
    }

}

ll mod_inverse(ll n)
{

      return pow_mod(n,mod-2);
}



