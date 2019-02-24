#include<iostream>
#include<bits/stdc++.h>
#define Max 1000100


using namespace std;

void Gen_prime();
long long lcm(long long a,long long b);
void Gen_prime_fact_1(long long n);
void Gen_prime_fact(long long n);
long long power(int base, int p);
long long comp();

bool sieve[Max+1];
vector<int>vct;
int factor_lcm[Max+1];
int factor_lcm1[Max+1];



int main()
{

    Gen_prime();
    int tc;
    long long a,b,l1,l;

    scanf("%d",&tc);

    for(int cs=1; cs<=tc; cs++)
    {
        scanf("%lld %lld %lld",&a,&b,&l);
        l1=lcm(a,b);

        Gen_prime_fact(l);
        Gen_prime_fact_1(l1);

        long long ans=comp();

        printf("Case %d: ",cs);
        if(ans==-1)
            printf("impossible\n");
        else
            printf("%lld\n",ans);






    }




}

long long power(int base, int p)
{
    if(p==0)
        return 1;

    long long ans=1;

    for(int i=1;i<=p;i++)
    {
        ans*=base;
    }

    return ans;
}

long long comp()
{
    long long ans=1;

    for(int i=2;i<=1000000;i++)
    {
        if(factor_lcm1[i]>factor_lcm[i])
            return -1;

        if(factor_lcm[i]>factor_lcm1[i])
        {
            ans*=power(i,factor_lcm[i]);

        }
    }
    return ans;


}

long long lcm(long long a,long long b)
{
    return (a*b)/__gcd(a,b);
}


void Gen_prime_fact_1(long long n)
{
    memset(factor_lcm1,0,sizeof(factor_lcm1));

    if(n==1)
        return;

    if(n<1000000)
    {
        if(!sieve[n])
        {
           factor_lcm1[n]++;
           return;
        }
    }
    int i=0;
    while(n>1 && vct[i]<=sqrt(n) && i<vct.size())
    {
        if(n<1000000)
        {
            if(!sieve[n])
            {
              factor_lcm1[n]++;
              return;
            }
        }
        int cnt=0;
        while(n%vct[i]==0)
        {
            n=n/vct[i];
            cnt++;
        }
        factor_lcm1[vct[i]]+=cnt;

        i++;
    }

    if(n!=1)
    {
        factor_lcm1[n]++;
              return;
    }
}



void Gen_prime_fact(long long n)
{
    memset(factor_lcm,0,sizeof(factor_lcm));

    if(n==1)
        return;

    if(n<1000000)
    {
        if(!sieve[n])
        {
           factor_lcm[n]++;
           return;
        }
    }
    int i=0;
    while(n>1 && vct[i]<=sqrt(n) && i<vct.size())
    {
        if(n<1000000)
        {
            if(!sieve[n])
            {
              factor_lcm[n]++;
              return;
            }
        }
        int cnt=0;
        while(n%vct[i]==0)
        {
            n=n/vct[i];
            cnt++;
        }
        factor_lcm[vct[i]]+=cnt;

        i++;
    }

    if(n!=1)
    {
        factor_lcm[n]++;
              return;
    }
}




void Gen_prime()
{
    for(int i=4;i<=Max;i+=2)
        sieve[i]=1;

    for(int i=3;i<=sqrt(Max);i++)
    {
        if(!sieve[i])
        {
            for(int j=i*i ;j<=Max;j+=2*i)
            {
               sieve[j]=1;
            }
        }
    }

    vct.push_back(2);

    for(int i=3;i<=Max;i+=2)
    {
        if(!sieve[i])
            vct.push_back(i);
    }
}

