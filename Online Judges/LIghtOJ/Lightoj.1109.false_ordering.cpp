#include<iostream>
#include<bits/stdc++.h>
#define Max 1010

using namespace std;

bool sieve[Max+1];

vector<int>prime;

void Genprime()
{
    for(int i=4;i<=Max;i+=2)
        sieve[i]=1;

    for(int i=3;i*i<=Max;i+=2)
    {
        if(!sieve[i])
        {
            for(int j=i*i; j<=Max; j+=2*i)
            {
                sieve[j]=1;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=Max;i+=2)
    {   if(!sieve[i])
        {
            prime.push_back(i);
        }
    }
}


long long sum_of_div(long long n)
{
    long long ans=1;
    if(n==1)
        return 1;

    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n ;i++)
    {

        if(sieve[n]==0)
        {
         return ans*=2;
        }

        int cnt=0;
        while(n%prime[i]==0)
        {
            n=n/prime[i];
            cnt++;
        }
        ans*=(cnt+1);

    }

    if(n!=1)
        ans*=2;

    return ans;

}

struct node
{
    int n;
    int div;
}d_sum[1000];

bool comp(node a,node b)
{
    if(a.div==b.div)
        return a.n>b.n;
    else
    return a.div<b.div;
}

int main()
{

    int tc,index;
    Genprime();

    for(int i=1;i<=1000;i++)
    {
        d_sum[i-1].n=i;
        d_sum[i-1].div=sum_of_div(i);
    }

    sort(d_sum,d_sum+1000,comp);

    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%d",&index);
         printf("Case %d: %d\n",cs,d_sum[index-1]);
    }

}
