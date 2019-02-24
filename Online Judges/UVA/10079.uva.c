#include<stdio.h>
int main()
{
    unsigned  long long int n;
    while(scanf("%lld",&n)==1 && n>=0)
    {
        if(n==0)
            printf("1\n");
        else
            printf("%d\n",(n*(n+1)/2)+1);
    }
    return 0;
}
