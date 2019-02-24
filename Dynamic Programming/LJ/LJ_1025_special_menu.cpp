#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long dp[101][101];
string str;

long long solve(int i,int j)
{
    if(i>j)
        return 0;

    if(i==j)
        return 1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    long long res;
    res=0;

    if(str[i]==str[j])
        res=1+solve(i+1,j)+solve(i+1,j-1)+solve(i,j-1)-solve(i+1,j-1);
    else
        res=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);

    return dp[i][j]=res;

}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int cs=1 ; cs<= tc ; cs++)
    {
        cin>>str;

        int l=str.size();

        for(int i=0; i<=l ; i++)
            for(int j=0; j<=l ; j++)
            dp[i][j]=-1;

        printf("Case %d: %lld\n",cs,solve(0,l-1));

    }



    return 0;
}
