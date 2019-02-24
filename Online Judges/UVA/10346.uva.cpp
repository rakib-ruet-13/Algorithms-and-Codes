#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
    long long int n,k,d,sum;
    while(scanf("%lld %lld",&n,&k)==2)
    {
        sum=n;
        while(n/k!=0)
        {
            sum=sum+n/k;
            n=n/k+n%k;
        }
        printf("%lld\n",sum);
    }
return 0;
}
