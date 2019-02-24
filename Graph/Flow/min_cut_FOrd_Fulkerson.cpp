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
#define Max 100

vector<int>graph[Max];
vector<int>graph_org[Max];

int cap[Max][Max];
int visited[Max];
int par[Max];
vector< pair<int,int> >cut_node;

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



void dfs(int u)
{
    visited[u]=1;
    for(int i=0 ; i< graph_org[u].size() ;i++)
    {
        int v=graph_org[u][i];

        if(visited[v]==0)
        {
            if(cap[u][v]==0)
            {
                cut_node.pb(make_pair(u,v));
                continue;
            }
            else
            {
                dfs(v);
            }
        }
    }




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


    mem(visited,0);

    dfs(src);

    for(int i=0 ;i<cut_node.size() ;i++)
    {
        cout<<cut_node[i].first-1<<" - "<<cut_node[i].second-1<<endl;
    }

    return max_flow;

}


void Input()
{
    read(node);
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
        graph_org[u].push_back(v);

        cap[u][v]=w;
    }

}


int main()
{
    int tc;
    read(tc);
    REP(cs,tc)
    {
        Input();
        int src,sink;
        read(src);
        read(sink);
        printf("Case %d: %d\n",cs,Ford_Fulkerson(src,sink));
    }

}

