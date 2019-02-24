#include<iostream>
#include<bits/stdc++.h>
#define mod 100000000

using namespace std;




long long int dp[110][110][15][15];

long long int n1,n2,k1,k2;

long long int solve(int i,int j,int p,int q)
{

    if(i>n1 || j>n2 || p>k1 || q>k2)
        return 0;

    if(i==n1 && j==n2)
        return 1;


    if(dp[i][j][p][q]!=-1)
        return dp[i][j][p][q];

    long long int res1,res2,res3,res4;

    res1=solve(i+1,j,p+1,0)%mod;
    res2=solve(i,j+1,0,q+1)%mod;

    return dp[i][j][p][q]=((res1)%mod+(res2%mod))%mod;

}

int main()
{

    cin>>n1>>n2>>k1>>k2;

    for(int i=0 ;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            for(int h=0;h<=k1;h++)
            {
                for(int m=0;m<=k2;m++)
                    dp[i][j][h][m]=-1;
            }
        }
    }

    cout<<solve(0,0,0,0)<<endl;

}
