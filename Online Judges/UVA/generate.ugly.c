#include<stdio.h>
int main()
{
   static int i,j,k,num;
    i=1;
    k=1;
    num=1;
    j=1;
    while(i<1500)
    {

       while(1)
        {if(k==1)
            {num=num*2;
             k=2;
             i++;
             printf("%d   ",num);
            }
            if(k==2)
            {
                num=num*3;
                k=3;
                i++;
                   printf("%d   ",num);
            }
            if(k==3)
                {num=num*4;
                k=4;
                   printf("%d   ",num);
                i++}
                if(k==4)
                {
                    num=num*4;
                    k=1;
                       printf("%d   ",num);
                    i++;
                    break;
                }
                }





    }
}
