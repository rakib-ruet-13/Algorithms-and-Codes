#include<stdio.h>
#include<math.h>
int main()
{
    int t,x,y,r,i;
    float min,max;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
    scanf("%d %d %d",&x,&y,&r);
    min=(float)r-(float)(sqrt(x*x+y*y));
    max=(float)r+(float)(sqrt(x*x+y*y));
    printf("%.2f %.2f\n",min,max);
    }
    return 0;
}
