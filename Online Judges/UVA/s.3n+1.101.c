#include<stdio.h>
int main()
{
     int x,y,n,temp;
     int sum,i,check;

     while(scanf("%d  %d",&x,&y)==2)

       {
           printf("%d %d",x,y);
          check=0;

         if(y<x)
         {
             temp=x;
             x=y;
             y=temp;
         }
            for(i=x;i<= y;i++)
           {
             n=i;
              sum=1;

                while(n>1)

                {

                    if(n%2==0)
                        n=n/2;

                    else
                          n=3*n+1;
                            sum++;
                  }
                    if(check<sum)
                    check=sum;
                }
                 printf(" %d\n",check);
     }
   return 0;
}


