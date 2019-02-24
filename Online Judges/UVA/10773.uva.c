#include<stdio.h>
#include<math.h>
int main()
{
    int tc,i;
    double d,v,u,s1,s2;
    scanf("%d",&tc);
    for(i=1;i<=tc;i++)
    {
        scanf("%lf %lf %lf",&d,&v,&u);
        if( u==0 || v>=u)
            printf("Case %d: can't determine\n",i);
        else
        {
            s1=d/u;
            s2=d / sqrt(u*u-v*v);
            printf("Case %d: %.3lf\n",i,fabs(s2-s1));
        }
    }

    return 0;


}

