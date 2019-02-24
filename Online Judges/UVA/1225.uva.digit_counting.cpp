#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{

    int N,i,num,rem,tc,arr[10];
    cin>>tc;
    while(tc--)
    {
        for(i=0;i<=9;i++)
            arr[i]=0;
        cin>>N;
        for(i=1;i<=N;i++)
        {
            num=i;
            if(i>9)
            {
                while(num)
                {
                    rem=num%10;
                    arr[rem]++;
                    num=num/10;
                }

            }
            else
                arr[i]++;
        }
        for(i=0;i<10;i++)
            if(i!=9)
                printf("%d ",arr[i]);
            else
                printf("%d",arr[i]);
            if(tc!=0)printf("\n");

    }
    return 0;

}
