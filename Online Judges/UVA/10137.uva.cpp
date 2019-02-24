#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
    double arr[1020],sum,avg,sum1,diff;
    int i,n;

    while(cin>>n && n!=0)
    {
        sum=0;
        for(i=0;i<n;i++)
            {
                cin>>arr[i];
                sum=sum+arr[i];
            }

            avg=sum/n;

            sum=0;
            sum1=0;
            diff=0;

        for(i=0;i<n;i++)
        {
            diff=(double)(long)((arr[i]-avg)*100)/100;

                if(diff>0)
                    sum=sum+diff;
                else
                    sum1=sum1-diff;
        }

        if(sum>sum1)
         printf("$%.2f\n",sum);
         else
             printf("$%.2f\n",sum1);



    }
    return 0;
}
