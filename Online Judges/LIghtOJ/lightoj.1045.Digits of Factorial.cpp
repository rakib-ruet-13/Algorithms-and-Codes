#include<iostream>
#include<bits/stdc++.h>
#define Max 1000010
using namespace std;


double dp[Max+1];

int main()
{

    int tc;
    int n,base;

    dp[0]=0;
    for(int i=1;i<=Max;i++)
    {
        dp[i]=dp[i-1]+log((double)i);
    }


    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%d %d",&n,&base);

        double x=dp[n]/log(base);

        int n=floor(x);

        printf("Case %d: %d\n",cs,n+1);



    }

    return 0;



}
