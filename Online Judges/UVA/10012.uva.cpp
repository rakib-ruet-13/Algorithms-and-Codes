#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int tc;
    int n,i;
    double a[50],f;
    double sum;
    float w;
    cin>>tc;
    while(tc--)
    {
        w=-1;
        sum=0;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>f;
        a[i]=f/2;
        if(a[i]>=w)
            w=a[i];
    }
    for(i=0;i<n-1;i++)
    {
        sum=sum+sqrt((a[i]+a[i+1])*(a[i]+a[i+1])   - (a[i]-a[i+1])*(a[i]-a[i+1]));
    }
    sum=sum+a[0]+a[n-1];

    printf("%.3lf\n",sum*2*w);
    }
}
