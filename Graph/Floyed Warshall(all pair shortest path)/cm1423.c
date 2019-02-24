#include<stdio.h>
int main()
{
    long long int t,a,b,c;
    scanf("%lld",&t);
    for(a=1;a<=t;a++)
    {
       scanf("%lld",&c);
       printf("%lld\n",(c*(c-1))/2);
    }
}
