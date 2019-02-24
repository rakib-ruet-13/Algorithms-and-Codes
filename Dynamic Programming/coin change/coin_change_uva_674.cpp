#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int coin[100];

int dp[101][10001];
int amount,n;

int fun(int i, int val)
{
    if(i>=n+1)
    {
        if(val==0)
            return 1;
        else
            return 0;
    }

    if(dp[i][val]!=-1)
        return dp[i][val];

    int res1=0;
    int res2=0;
    if(val-coin[i]>=0)
    {
        res1=fun(i,val-coin[i]);
    }
    res2=fun(i+1,val);

    return dp[i][val]=res1+res2;
}


int main()
{

    coin[1]=1;
    coin[2]=5;
    coin[3]=10;
    coin[4]=25;
    coin[5]=50;
    n=5;
    for(int i=0;i<=6;i++)
    {
        for(int j=0;j<=10000;j++)
            dp[i][j]=-1;
    }

    while(cin>>amount)
    {
        cout<<fun(1,amount)<<endl;
    }
}

