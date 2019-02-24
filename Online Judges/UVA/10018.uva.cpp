#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

long long int REV(long long int temp)
{
    long long int sum=0;
    int i=0;
    while(temp)
    {
        sum=sum*10+temp%10;
        temp=temp/10;
        i++;
    }
    return sum;
}

int main()
{
    int tc;
    long long int num,temp,sum,cnt;
    cin>>tc;
    while(tc--)
    {
        cnt=0;
        scanf("%lld",&num);
        sum=num;
        temp=0;
        do
        {
            sum=sum+temp;
            temp=REV(sum);
            cnt++;

        }
        while(temp!=sum);

        printf("%lld %lld\n",cnt-1,sum);

    }
    return 0;


}

