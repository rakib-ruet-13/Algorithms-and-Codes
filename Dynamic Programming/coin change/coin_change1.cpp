#include<iostream>
#include<bits/stdc++.h>
#define mod 100000007
using namespace std;

int n,k;
int coin[110];
int amount[110];

long long dp[110][1001][21];

long long int fun(int i,int curr,int used)
{

    if(i>=n+1)
    {
        if(curr==k)
            {
                return 1;
            }
        else
            return 0;
    }

    if(curr>k)
        return 0;


    if(dp[i][curr][used]!=-1)
       return dp[i][curr][used];

    long long res1,res2;
    res1=0;
    res2=0;

    if(coin[i]+curr<=k && used<amount[i])
    {
        res1=fun(i,curr+coin[i],used+1);
    }

    res2=fun(i+1,curr,0);

    return dp[i][curr][used]=((res1%mod)+(res2%mod))%mod;

}





int main()
{


    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc; cs++)
    {

        scanf("%d %d",&n,&k);


        for(int i=0;i<=n;i++)
            for(int j=0;j<=k;j++)
              for(int p=0;p<=20;p++)
        {
            dp[i][j][p]=-1;
        }

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&coin[i]);
        }


        for(int i=1;i<=n;i++)
        {
            scanf("%d",&amount[i]);
        }

        printf("Case %d: %lld\n",cs,fun(1,0,0));


    }





    return 0;

}
