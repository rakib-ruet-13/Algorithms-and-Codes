#include<stdio.h>
#include<stdlib.h>

int main()
{
            int n,i,r,k,j,min,temp,sum,s[40000];
            while(scanf("%d",&n)==1)

         {
             for(i=0;i<n;i++)
        {
            scanf("%d",&r);
            for(j=0;j<r;j++)
                scanf("%d",&s[j]);
                for(j=0;j<r;j++)
                   {
                    for(k=0;k<r-1;k++)
                         {
                            if(s[k]>s[k+1])
                              {
                                   temp=s[k];
                                    s[k]=s[k+1];
                                    s[k+1]=temp;
                             }
                         }
                   }



            for(k=0;k<r;k++)
            {
            sum=0;
            for(j=0;j<r;j++)
            {
              sum=sum+abs(s[j]-s[k]);
            }
               if(k==1)
                 min=sum;
              if(sum<min)
                min=sum;
            }
            printf("%d\n",min);

        }
         }

       return 0;

}
