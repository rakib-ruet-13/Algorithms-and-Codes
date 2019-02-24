#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 100010
#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x);
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)


vector<int>graph[Max];
int node,edge;
int dp[Max][3];
int par[Max];


int solve(int curr, int guard)
{

    if(node==1)
        return 1;

    if(dp[curr][guard]!=-1)
    return dp[curr][guard];

    int sum=0;

    for(int i=0; i<graph[curr].size() ; i++)
    {
        int v=graph[curr][i];

        if(v!=par[curr])
        {
           par[v]=curr;

           if(guard==0)
                sum=sum+solve(v,1);
           else
                sum=sum+ min( solve(v,0) , solve(v,1 ));
        }
    }

    return dp[curr][guard]=sum+guard;
}


int main()
{
    int tc;
    read(tc);

    REP(cs,tc)
    {
        read(node);
        read(edge);

        REP(i,edge)
        {
            int u,v;
            read(u);
            read(v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        for(int i=0; i<=node ;i++)
            for(int j=0; j<=1 ;j++)
            dp[i][j]=-1;


        write(min(solve(1,0),solve(1,1)));


        REP(i,node)
        graph[i].clear();

    }
}
