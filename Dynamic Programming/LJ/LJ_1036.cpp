#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int U[505][505];
int R[505][505];

long long dp[505][505][2];

long long solve(int x,int y,int dir)
{
    if(x<1 || y<1)
      return 0;

    if(dp[x][y][dir]!=-1)
        return dp[x][y][dir];

    ll res=0;

    if(dir==0)
    {
        res=U[x][y]+solve(x,y-1,0)+max(solve(x-1,y,0),solve(x-1,y,1))-max(solve(x-1,y-1,0),solve(x-1,y-1,1));

    }
    else
    {
        res=R[x][y]+solve(x-1,y,1)+max(solve(x,y-1,0),solve(x,y-1,1))-max(solve(x-1,y-1,0),solve(x-1,y-1,1));
    }

    //cout<<x<<" xy "<<y<<"  res "<<res<<endl;

    return dp[x][y][dir]=res;



}

int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n,m;

        scanf("%d %d",&n,&m);

        for(int i=1; i<=n ; i++)
            for(int j=1; j<=m; j++)
        {
            scanf("%d",&U[i][j]);
        }

        for(int i=1; i<=n ; i++)
            for(int j=1; j<=m; j++)
        {
            scanf("%d",&R[i][j]);
        }

        memset(dp,-1,sizeof(dp));

        printf("Case %d: %lld\n",cs,max(solve(n,m,0),solve(n,m,1)));


    }


    return 0;
}
