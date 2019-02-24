#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long dp[1010000];
long long dp1[1010000];

int main()
{

    dp[1]=1;
    dp1[1]=1;
    for(int i=2;i<=1000100 ;i++)
    {
        dp[i]=(i-1)*6+dp[i-1];

        dp1[i]=dp1[i-1]+dp[i];
    }


    int tc;
    int n;
    scanf("%d",&tc);
    for(int i=1; i<=tc;i++)
    {
        scanf("%d",&n);

        printf("Case %d: %lld %lld\n",i,dp[n],dp1[n]);
    }
}
