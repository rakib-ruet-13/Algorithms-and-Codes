#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define mod 100000007

long long dp[10001];

int main()
{

    int tc;

    scanf("%d",&tc);

    int coin[101];

    int k,n;

    for(int cs=1 ; cs<= tc ; cs++)
    {


         memset(dp,0,sizeof(dp));

         scanf("%d %d",&n,&k);

            for(int i=1 ;i<=n ;i++)
            {
                scanf("%d",&coin[i]);
            }
         dp[0]=1;

         for(int i=1; i<=n ;i++)
         {
            for(int j=coin[i]; j<=k ;j++)
            {
                    dp[j]=(dp[j]+dp[j-coin[i]])%mod;
            }
         }

         printf("Case %d: %lld\n",cs,dp[k]);

    }





    return 0;
}
