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

int dinic(int src,int sink)
{
    int flow=0;

    int INF=100000000;
    while(1)
    {
        if(!bfs(src,sink)) break;
        mem(ind,0);
        while(int curr_flow=dfs(src,INF,sink))
            flow+=curr_flow;
    }
    return flow;
}


struct edge
{
    int u;
    int v;
    int w;
};

edge arr[100100];

int lim;
int N,M,k;

int Inp(int st,int p)
{


    int INF=100000000;

    for(int i=st; i<=p; i++)
    {
        int u=arr[i].u;
        int v=arr[i].v;

        if(u==0 && v==N+1)
        {
            graph[0].push_back(2*N+1);
            cap[0][2*N+1]+=1;
            graph[2*N+1].push_back(0);
            continue;
        }

        else
        {
            graph[2*u].push_back(2*v-1);
            cap[2*u][2*v-1]+=1;
            graph[2*v-1].push_back(2*u);

        }

    }

    return dinic(0,2*N+1);


}

bool comp(edge a, edge b)
{
    return a.w<b.w;
}

int main()
{
    //freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);


    for(int cs=1 ; cs<=tc ;cs++)
    {
        scanf("%d %d",&N,&M);

        lim=0;

        for(int i=0; i<M; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            arr[i].u=min(u,v);
            arr[i].v=max(u,v);
            arr[i].w=w;
            lim=max(lim,w);
        }

        scanf("%d",&k);


        sort(arr,arr+M,comp);

        for(int i=0; i<Max; i++)
           graph[i].clear();
         mem(cap,0); mem(f,0);


         for(int i=1; i<=N; i++)
         {
             graph[2*i-1].push_back(2*i);
              cap[2*i-1][2*i]=1;
             graph[2*i].push_back(2*i-1);

         }

        int ind=-1;
        int res=0;


        for(int i=0; i<M; i++)
        {
            res+=Inp(i,i);
            if(res>=k)
            {
                ind=i;
                break;
            }
        }

        if(ind==-1)
            printf("Case %d: no solution\n",cs);
        else
            printf("Case %d: %d\n",cs,arr[ind].w);
    }
    return 0;
}
