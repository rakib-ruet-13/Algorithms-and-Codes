#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int coin[]={1,5,10,25,50};
long long dp[6][30010];

long long solve(int pos,int rem)
{
    if(pos>4)
    {
        if(rem==0)
            return 1;
        else
            return 0;
    }

    if(rem<0)
        return 0;

    if(dp[pos][rem]!=-1)
        return dp[pos][rem];

    long long res1,res2;
    res1=0;
    res2=0;

    if(coin[pos]<=rem)
    {
        res1=solve(pos,rem-coin[pos]);
    }
    res2=solve(pos+1,rem);

    return dp[pos][rem]=res1+res2;


}


int main()
{
     int  n;

     for(int i=0;i<=5;i++)
            for(int j=0;j<=30008;j++)
            {
                dp[i][j]=-1;
            }

    while(scanf("%d",&n)==1)
    {
       long long int res=solve(0,n);

       if(res>1)
       printf("There are %lld ways to produce %d cents change.\n",res,n);
       else
        printf("There is only 1 way to produce %d cents change.\n",n);

    }

    return 0;
}
