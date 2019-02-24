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
        if(amount==val)
            return 1;
        else
            return 0;
    }

    if(dp[i][val]!=-1)
        return dp[i][val];

    int res1=0;
    int res2=0;
    if(val+coin[i]<=amount)
    {
        res1=fun(i,val+coin[i]);
    }
    res2=fun(i+1,val);

    return dp[i][val]=res1+res2;
}


int main()
{
    int tc;
    cin>>tc;

    for(int cs=1; cs<=tc; cs++)
    {
        cin>>n>>amount;

        for(int i=1; i<=n ;i++)
        {
            cin>>coin[i];
        }

        for(int i=0;i<=n;i++)
            for(int j=0;j<=amount;j++)
        {
            dp[i][j]=-1;
        }

        cout<<fun(1,0)<<endl;
    }
}
