#include<stdio.h>
int main()
{
    int t;
    while(scanf("%d",&t)==1 && t!=0)

    {
        int i, l,w,h;
        int oldh=-999,sum=0,max=0;
        for(i=1;i<=t;i++)
        {
            scanf("%d %d %d",&l,&w,&h);
            sum=l*w*h;

              if(h==oldh)
            {
                if(sum>max)
                    max=sum;
            }

            if(h>oldh)
            {  oldh=h;
                max=sum;
            }


        }
        printf("%d\n",max);

    }
    return 0;
}
