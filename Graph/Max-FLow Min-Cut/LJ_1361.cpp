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
#define Max 210

using namespace std;

vector<int>graph[Max+1];
int cap[Max+1][Max+1],f[Max+1][Max+1];
int d[Max+1];
int vis[Max+1];

void addEdge(int a,int b,int c,int flow)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
    cap[a][b]=c;
    f[a][b]=flow;

}
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

ll dinic(int src,int sink)
{
    ll flow=0;

    int INF=1100000000;
    while(1)
    {
        if(!bfs(src,sink)) break;

        mem(ind,0);

        while(int curr_flow=dfs(src,INF,sink))
            flow+=curr_flow;
    }

    return flow;

}

int u[202];
int v[202];
int c[202];

void Inp()
{

    for(int i=0; i<Max; i++)
        graph[i].clear();

    int node,edge;

    mem(cap,0); mem(f,0);

    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1; i<=n ; i++)
        scanf("%d",&u[i]);
    for(int j=1; j<=n; j++)
        scanf("%d",&v[j]);

    for(int i=1; i<=n; i++)
    {
        int temp;
        scanf("%d",&temp);

        if(temp==0)
        {
            addEdge(0,i,u[i],0);
            addEdge(i,n+1,v[i],0);

        }
        else if(temp==1)
        {
            addEdge(0,i,u[i],0);
            addEdge(i,n+1,1100000000,0);
        }
        else
        {
            addEdge(0,i,1100000000,0);
            addEdge(i,n+1,v[i],0);
        }
    }
    while(m--)
    {
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);

        addEdge(p,q,r,0);
        addEdge(q,p,r,0);

    }

    long long res=dinic(0,n+1);

    printf(" %lld\n",res);



}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc; cs++)
    {
        printf("Case %d:",cs);
        Inp();
    }




    return 0;
}



