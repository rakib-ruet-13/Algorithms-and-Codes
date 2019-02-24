#include<iostream>
#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

 int tw;
 int cost[1010];
 int w[1010];
 int dp[1001][1001];

ll knapsack(int curr,int i,int n)
{
    if(i==n+1)
        return 0;


    ll profit1=0;
    ll profit2=0;
    if(dp[curr][i]!=-1)
        return dp[curr][i];

    if(curr+w[i]<=tw)
    {
         profit1=cost[i]+knapsack(curr+w[i],i+1,n);
    }

        profit2=knapsack(curr,i+1,n);


    return dp[curr][i]=max(profit1,profit2);


}


int main()
{
    int n;
    int tc;

    cin>>tc;

    for(int cs=1 ;cs<=tc ;cs++){
    cin>>n;

    for(int i=1;i<=n ;i++)
    {
        cin>>cost[i]>>w[i];
    }

    int k;
    cin>>k;

    long long res=0;
    for(int i=1 ;i<=k;i++)
    {
        cin>>tw;

        for(int i=0 ;i<=tw;i++)
            for(int j=0 ; j<= n ;j++)
        {
            dp[i][j]=-1;
        }

        res+=knapsack(0,1,n);


    }

    cout<<res<<endl;


    }
}
