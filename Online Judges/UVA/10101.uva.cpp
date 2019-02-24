#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long long int arr[9];
    long long int num,sum,cs=0,i,flag,n;

    while(cin>>num)
    {
        n=num;
       arr[0]=num/100000000000000;
       num=num%100000000000000;
       arr[1]=num/1000000000000;
       num=num%1000000000000;
       arr[2]=num/10000000000;
       num=num%10000000000;
       arr[3]=num/1000000000;
       num=num%1000000000;
       arr[4]=num/10000000;
       num=num%10000000;
       arr[5]=num/100000;
       num=num%100000;
       arr[6]=num/1000;
       num=num%1000;
       arr[7]=num/100;
       num=num%100;
       arr[8]=num;
       printf("%4d.",++cs);
       flag=0;
       for(i=0;i<9;i++)
       {
           if(arr[i]!=0 || (flag!=0 && i==4))
           {
               flag=1;
               if(arr[i]!=0)
               {
                    printf(" ");
                    printf("%lld",arr[i]);
               }

               if(i==0 || i==4)
                printf(" kuti");
               if(i==1 || i==5)
                printf(" lakh");
               if(i==2 || i==6)
                printf(" hajar");
               if(i==3 || i==7)
                printf(" shata");
           }
       }
       if(n==0)
        cout<<" "<<n;
       printf("\n");
    }





}
