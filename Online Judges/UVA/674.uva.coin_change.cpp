#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    long long int coin[]={1,5,10,25,50},arr[7490]={0};
    int n,i;
    arr[0]=1;
    for(i=0;i<5;i++)
    {
        for(n=coin[i];n<7490;n++)
        {
            arr[n]=arr[n]+arr[n-coin[i]];
        }
    }

    while(cin>>n)
    {
        printf("%lld\n",arr[n]);
    }
    return 0;
}
