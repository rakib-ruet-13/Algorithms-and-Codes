#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    double r,pi;
    double ans,area1,area2;

    int tc,i;

    pi=2*acos(0.0);
    cin>>tc;
    for(i=1;i<=tc;i++)
    {
        cin>>r;
        area1=4*r*r;
        area2=pi*r*r;
        ans=area1-area2;
        printf("Case %d: %.2f\n",i,ans);
    }
    return 0;
}

