#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n;

int dp[101][12010];
int cost[101];
int profit[101];

int solve(int pos , int spent,int budget,int used)
{
    if(pos>n || spent>budget)
        return 0;

    if(dp[pos][spent]!=-1)
    {
        return dp[pos][spent];
    }

    int res1,res2;
    res1=res2=0;


    if(spent+cost[pos]>2000 && spent+cost[pos]<=(budget+200) && !used)
    {
        res1=profit[pos]+solve(pos+1,spent+cost[pos],budget+200,1);
    }
    else if(spent+cost[pos]<=budget )
    {
        res1=profit[pos]+solve(pos+1,spent+cost[pos],budget,used);
    }

    res2=solve(pos+1,spent,budget,used);


    return dp[pos][spent]=max(res1,res2);
}


int main()
{

    int budget;

    while(cin>>budget>>n)
    {


        for(int i=0;i<=n;i++)
            for(int j=0;j<=budget+200;j++)
            dp[i][j]=-1;


        for(int i=1;i<=n;i++)
        {
            cin>>cost[i]>>profit[i];
        }

        cout<<solve(1,0,budget,0)<<endl;
    }

}
