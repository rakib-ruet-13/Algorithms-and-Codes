#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long long int tc,n,b,c;
    long long int sum,a;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            sum=sum+a*c;
        }
        printf("%lld\n",sum);

    }

    return 0;
}
