#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x)
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)
#define mem(x,val) memset(x,val,sizeof(x))
#define Max 105

vector<int>graph[Max];
int cap[Max][Max];
int visited[Max];
int par[Max];

int node,edge;


bool bfs(int src,int sink)
{
    mem(visited,0);
    mem(par,-1);

    visited[src]=1;
    queue<int>q;

    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        if(u==sink)
            return true;

        for(int i=0; i< graph[u].size()  ; i++ )
        {
            int v=graph[u][i];

            if(visited[v]==0 && cap[u][v]>0)
            {
                visited[v]=1;
                par[v]=u;
                q.push(v);
            }
        }
    }

    return false;
}


int Ford_Fulkerson(int src,int sink)
{
    int max_flow=0;

    while(bfs(src,sink))
    {

        int mn=inf;

        for(int v=sink ; v!=src ; v=par[v])
        {
            int u=par[v];
            mn=min(mn,cap[u][v]);
        }

        for(int v=sink ; v!=src ; v=par[v])
        {
            int u=par[v];
            cap[u][v]-=mn;
            cap[v][u]+=mn;
        }

        max_flow+=mn;

    }
    return max_flow;

}


void Input()
{

    read(edge);

    for(int i=0;i<=node; i++)
        for(int j=0;j<=node;j++)
    {
        cap[i][j]=0;
    }

    for(int i=0;i<=node; i++)
        graph[i].clear();


    REP(i,edge)
    {
        int u,v,w;
        read(u);
        read(v);
        read(w);

        graph[u].push_back(v);
        graph[v].push_back(u);

        cap[u][v]+=w;
        cap[v][u]+=w;
    }

}


int main()
{
    int tc;
    read(tc);
    REP(cs,tc)
    {

        int src,sink;

        read(node);
        read(src);
        read(sink);

        Input();


        printf("Case %d: %d\n",cs,Ford_Fulkerson(src,sink));


    }

}

