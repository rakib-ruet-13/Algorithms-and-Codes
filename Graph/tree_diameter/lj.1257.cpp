#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x);
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)
#define mem(x,val) memset(x,val,sizeof(x))
#define Max 50001

vector<int>graph[Max];
vector<int>cost[Max];

int visited[Max];
int dp[Max];
int dp1[Max];
int dp2[Max];
int d[Max];
int par[Max];

int mx,src;

int dfs(int u)
{
    visited[u]=1;

    if(d[u]>mx)
    {
        mx=d[u];
        src=u;
    }

    for(int i=0 ;i< graph[u].size() ; i++)
    {
        int v=graph[u][i];

        if(v==par[u])
            continue;

        if(visited[v]==0)
        {
            par[v]=u;

            d[v]=d[u]+cost[u][i];

            dfs(v);
        }
    }
}


void CLEAR()
{
      mem(visited,0);
      mem(d,0);
      mem(par,0);
      mx=-1;

}

int node;
int edge;

int main()
{
    int tc;
    read(tc);

    REP(cs,tc)
    {
        read(node);
        edge=node-1;

        REP(i,edge)
        {
            int u,v,w;
            read(u);
            read(v);
            read(w);
            u++;
            v++;

            graph[u].pb(v);
            graph[v].pb(u);

            cost[u].pb(w);
            cost[v].pb(w);
        }

        CLEAR();

        dfs(1);

        int dm1=src;

        CLEAR();
        dfs(dm1);
        REP(i,node)
        {
            dp1[i]=d[i];
        }


        int dm2=src;

        CLEAR();
        dfs(dm2);
        REP(i,node)
        {
            dp2[i]=d[i];
        }

        printf("Case %d:\n",cs);

        REP(i,node)
        {
            printf("%d\n", max(dp1[i],dp2[i]));
        }

        REP(i,node)
        {
            graph[i].clear();
            cost[i].clear();
        }


    }

}
