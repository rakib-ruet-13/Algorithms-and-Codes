#include<iostream>
#include<stdio.h>

using namespace std;

long long int Sum_dig(int num)
{
    long long int temp=num;
    long long int sum=0;
    int i=0;
    while(temp)
    {
        sum=sum+temp%10;
        temp=temp/10;
        i++;
    }
    return sum;
}

int main()
{
    long long int num;

    while(scanf("%lld",&num)==1 && num!=0)
    {
        while(num>=10)
            num=Sum_dig(num);

        cout<<num<<endl;

    }

    return 0;

}
