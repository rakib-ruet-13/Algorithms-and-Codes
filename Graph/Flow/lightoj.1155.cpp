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
#define Max 205

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



    for(int i=0;i<=(node+1)*2 ; i++)
        for(int j=0;j<=(node+1)*2 ;j++)
    {
        cap[i][j]=0;
    }

    for(int i=0;i<=(node+1)*2; i++)
        graph[i].clear();


    for(int i=1;i<=node ;i++)
    {
        int w;
        read(w);

        int p=2*i-1;

        graph[p].pb(p+1);
        graph[p+1].pb(p);

        cap[p][p+1]=w;
        cap[p+1][p]=w;


    }

    read(edge);
    REP(i,edge)
    {
        int u,v,w;
        read(u);
        read(v);
        read(w);

        u=u*2;
        v=v*2-1;

        graph[u].push_back(v);
        graph[v].push_back(u);

        cap[u][v]=w;
    }

    int n,m;
    read(n);
    read(m);

    REP(i,n)
    {
        int temp;
        read(temp);

        temp=temp*2-1;
        graph[0].pb(temp);
        cap[0][temp]=inf;
    }

    REP(i,m)
    {
        int temp;
        read(temp);

        temp=temp*2;
        graph[temp].pb(node*2+1);
        cap[temp][node*2+1]=inf;
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
        Input();

        src=0;
        sink=node*2+1;

        printf("Case %d: %d\n",cs,Ford_Fulkerson(src,sink));

    }

}

