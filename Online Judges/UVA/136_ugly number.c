#include<stdio.h>
int main()
{
    int i,k,n=2;
    int num;

    for(i=2;n<=1500;i++)
    {
        num=i;
        while(num>0)
        {
            k=0;
            if(num%2==0)
                num=num/2;
            else if(num%3==0)
                num=num/3;
            else if(num%5==0)
               num=num/5;
               else if(num==1)
                break;
            else
            {
                k=1;
                break;
            }
        }
        if(k==0)
        {
             if(n==1500)
                printf("The 1500'th ugly number is <%d>.",i);
            ++n;

        }
    }

}
