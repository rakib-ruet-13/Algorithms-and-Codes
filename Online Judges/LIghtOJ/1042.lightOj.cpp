#include<iostream>
#include<stdio.h>
using namespace std;


static long long int arr[10000];


int bin_num(int n)
{
    int i,sum;

        sum=0;
        while(n!=0)
        {
            sum=sum+(n%2);
            n=n/2;

        }
    return sum;
}

int main()
{



    long long int tc,num,test,i,j,k;

    for(k=1;k<10000;k++)
    {
        test=bin_num(k);
        j=k+1;
        while(1)
        {
            if(bin_num(j)==test)
            {
                arr[i]=j;
                break;
            }
            else
                j++;
        }
    }

    scanf("%lld",&tc);

    for(i=1;i<=tc;i++)
    {
        scanf("%lld",&num);


        {
           if(num<10000)
             printf("Case %lld: %lld\n",i,arr[num]);
           else
           {


        test=bin_num(num);

        j=num+1;
        while(1)
        {
            if(bin_num(j)==test)
            {
                printf("Case %lld: %lld\n",i,j);
                break;
            }
            else
                j++;
        }
           }
        }

    }
    return 0;
}
