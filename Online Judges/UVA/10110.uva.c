#include<stdio.h>
#include<math.h>
int main()
{
    long long int i,d;

    while( scanf("%lld",&i)==1 && i!=0)
    {
    d=sqrt(i);
    if(d*d==i)
        printf("yes\n");
    else
        printf("no\n");
    }
    return 0;
}
