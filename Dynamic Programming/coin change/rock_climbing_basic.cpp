#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)


using namespace std;

int grid[1001][1001];
int dp[1001][1001];

int row,col;

long long int fun(int i,int j)
{
      if(!valid(i,j))
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    long long int res1,res2,res3;
    res1=0;
    res2=0;
    res3=0;

    res1=grid[i][j]+fun(i+1,j);
    res2=grid[i][j]+fun(i+1,j-1);
    res3=grid[i][j]+fun(i+1,j+1);

    res2=max(res1,res2);
    return dp[i][j]=max(res2,res3);
}

int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ;cs<=tc ;cs++)
    {
        scanf("%d %d",&row,&col);

        for(int i=1;i<=row;i++)
            for(int j=1;j<=col; j++)
        {
            scanf("%d",&grid[i][j]);
            dp[i][j]=-1;
        }

        int i,j;

        scanf("%d %d",&i,&j);

        printf("%lld\n",fun(i,j));
    }

}
