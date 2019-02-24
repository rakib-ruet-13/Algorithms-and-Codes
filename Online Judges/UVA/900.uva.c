#include<stdio.h>
int main()
{
    int i,d,a[51];
    a[0]=1;
    a[1]=1;
    for(i=2;i<=51;i++)
    {
        a[i]=a[i-2]+a[i-1];
    }
    while(scanf("%d",&d)==1)
    {
        if(d==0)
            break;
        else
         printf("%d\n",a[d]);
    }
    return 0;
}
