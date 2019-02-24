#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long long int N,rem,sum;


    while(cin>>N)
    {
        N++;
        sum=N-1;
        while(N>=3)
        {
            sum=sum+N/3;
            N=N/3+N%3;
        }
        printf("%lld\n",sum);
    }


    return 0;
}

