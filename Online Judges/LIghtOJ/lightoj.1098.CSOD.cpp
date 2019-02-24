#include<iostream>
#include<bits/stdc++.h>
using namespace std;


long long CSOD(long long n)
{
     long long sum=0;

     for(long long i=2;i*i<=n;i++)
     {
         long long j=n/i;

         sum+=(j*(j+1))/2-((i-1)*i)/2;
         sum+=i*(j-i);
     }

     return sum;


}

int main()
{
    long long int tc,n;

    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",cs,CSOD(n));
    }
    return 0;


}
