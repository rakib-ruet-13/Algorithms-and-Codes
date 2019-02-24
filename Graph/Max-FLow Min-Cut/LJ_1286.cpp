#include<bits/stdc++.h>
#include<iostream>
#define ll long long int
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define sci(a) scanf("%d",&a);
#define scl(a) scanf("%ld",&a);
#define scd(a) scanf("%lf",&a);
#define all(x) x.begin(),x.end()
#define sz size()
#define mem(x,a) memset(x,a,sizeof(x))
#define Max 204
using namespace std;

vector<int>graph[Max+1];
int cap[Max+1][Max+1],f[Max+1][Max+1];
int d[Max+1];
int vis[Max+1];


bool bfs(int src,int sink)
{
    mem(d,-1);
    d[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<graph[u].size() ; i++)
        {
            int v=graph[u][i];
            if(d[v]==-1 && (f[u][v]<cap[u][v]))
            {
                q.push(v);
                d[v]=d[u]+1;
            }
        }
    }
    return d[sink]!=-1;
}


int ind[Max+1]; /*** ind is the next operational stariting index of vertex***/

int dfs(int src,int flow,int sink)
{
    if(!flow) return 0;
    if(src==sink) return flow;

    for( ; ind[src]<graph[src].sz ; ++ind[src] )
    {
        int v=graph[src][ind[src]];
        if(d[v]!=d[src]+1) continue;

        int curr_flow=dfs(v, min(flow, cap[src][v]-f[src][v]),sink);

        if(curr_flow)
        {
            f[src][v]+=curr_flow;
            f[v][src]-=curr_flow;
            return curr_flow;
        }

    }
    return 0;
}

int dinic(int src,int sink)
{
    int flow=0;
    int INF=111111111;
    while(1)
    {
        if(!bfs(src,sink)) break;
        mem(ind,0);

        while(int curr_flow=dfs(src,INF,sink))
            flow+=curr_flow;
    }
    return flow;

}


void Inp()
{
    for(int i=0; i<Max; i++)
        graph[i].clear();

    int node,edge;

    mem(cap,0); mem(f,0);

    int n,m;

    scanf("%d %d",&n,&m);

    int sink=0+(n+m)+1;

    int sum=0;

    for(int i=1; i<=n; i++)
    {
        graph[0].push_back(i);
        graph[i].push_back(0);

        int w;
        scanf("%d",&w);
          cap[0][i]=w;
          sum+=w;

    }

    for(int i=n+1; i<=n+m; i++)
    {

       graph[i].push_back(sink);
       graph[sink].push_back(i);

        int w;
        scanf("%d",&w);
        cap[i][sink]=w;

    }


     for(int i=1; i<=n; i++)
     {
         int p;
         scanf("%d",&p);
         while(p--)
         {
             int u;
             scanf("%d",&u);
             u=u+n;

             graph[i].push_back(u);
             graph[u].push_back(i);

             cap[i][u]=10000000;

         }

     }




     printf(" %d\n",sum-dinic(0,sink));

}

int main()
{

    int tc;
    scanf("%d",&tc);
    for(int cs=1; cs<= tc ;cs++)
    {
        printf("Case %d:",cs);
        Inp();

    }

    return 0;
}



