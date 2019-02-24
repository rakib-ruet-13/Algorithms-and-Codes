#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long long int num1,num2;
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&num1,&num2);
        if(num1<num2)
            printf("<\n");
        else if(num1>num2)
            printf(">\n");
        else
            printf("=\n");

    }

    return 0;
}
