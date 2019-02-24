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

    int INF=111111111;
    while(1)
    {
        if(!bfs(src,sink)) break;
        mem(ind,0);
        while(int curr_flow=dfs(src,INF,sink))
            {
                flow+=curr_flow;
            }
    }
    return flow;

}

int arr[Max+1];

void Inp()
{


        int N,M;
        int INF=1000000000;

        mem(cap,0);
        mem(f,0);
        for(int i=0; i<Max; i++)
        graph[i].clear();


        scanf("%d",&N);

        for(int i=1; i<=N; i++)
        {
            scanf("%d",&arr[i]);

            graph[2*i-1].push_back(2*i);
            graph[2*i].push_back(2*i-1);
            cap[2*i-1][2*i]+=arr[i];

        }

        scanf("%d",&M);
        int u,v,w;

        while(M--)
        {
            scanf("%d %d %d",&u,&v,&w);
            graph[2*u].push_back(2*v-1);
            cap[2*u][2*v-1]+=w;
            graph[2*v-1].push_back(2*u);
        }

        int p,q;
        scanf("%d %d",&p,&q);

        for(int i=1; i<=p; i++)
        {
            scanf("%d",&u);
            graph[0].push_back(2*u-1);
            graph[2*u-1].push_back(0);
            cap[0][2*u-1]=INF;
        }

        for(int i=1; i<=q; i++)
        {
            scanf("%d",&v);
            graph[2*v].push_back(2*N+1);
            graph[2*N+1].push_back(2*v);
            cap[2*v][2*N+1]=INF;
        }

        printf(" %lld\n",dinic(0,2*N+1));



}

int main()
{

    int tc;
      //freopen("input.txt","r",stdin);
    scanf("%d",&tc);


    for(int cs=1; cs<=tc; cs++)
    {
        printf("Case %d:",cs);
        Inp();

    }

    return 0;
}


