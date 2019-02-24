#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool check(int n,int pos) { return n & (1<<pos); }
int Set(int n,int pos) {  return n= n | (1<<pos);}
int Reset(int n,int pos) { return n=n & ~(1<<pos);}


int n;
long long dp[1<<14];
long long cost[15][15];



long long solve(int mask)
{
    if(mask >= (1<<n)-1)
        return 0;

    if(dp[mask]!=-1)
        return dp[mask];


    long long mn=111111111111;


    for(int i=0;i<n;i++)
    {
        long long price=0;
        if(check(mask,i)==0)
        {
            price+=cost[i][i];

            for(int j=0;j<n;j++)
            {
                if(check(mask,j))
                {
                    if(i!=j)
                    price+=cost[i][j];
                }
            }

            price=price+solve((Set(mask,i)));

            mn=min(mn,price);

        }


    }

    return dp[mask]=mn;
}



int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
       scanf("%d",&n);

       for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
       {
           scanf("%d",&cost[i][j]);
       }

       memset(dp,-1,sizeof(dp));

       printf("Case %d: %lld\n",cs,solve(0));


    }

}

