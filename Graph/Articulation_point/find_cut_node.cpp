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
#define mem(x,val) memset(x,val,sizeof(x))

vector<int>graph[Max];
int node,edge;

int par[Max];
int art[Max];
int d[Max];
int visited[Max];
int low[Max];

int t;

void dfs(int u)
{

    t=t+1;
    low[u]=d[u]=t;

    visited[u]=1;

    int child=0;

    for(int i=0; i<graph[u].size() ; i++)
    {


        int v=graph[u][i];

        if(v==par[u])
            continue;

        if(visited[v]==1)
        {
            low[u]=min(low[u],d[v]);
        }
        else
        {
            child++;
            par[v]=u;
            dfs(v);

            low[u]=min(low[u],low[v]);

            if(d[u]<= low[v] && par[u]!=0)
                art[u]=1;

        }

        if(child>1)
         art[u]=1;
    }
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

        mem(d,0);
        mem(art,0);
        mem(par,0);
        mem(low,0);
        mem(visited,0);

        t=0;

        dfs(1);

        REP(i,node)
        {
            if(art[i])
                cout<<i<<" ";
        }
        cout<<endl;



        REP(i,node)
        graph[i].clear();


    }


    return 0;
}

