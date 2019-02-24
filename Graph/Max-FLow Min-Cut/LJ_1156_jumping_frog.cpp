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

                if(flow>=2)
                    return flow;
                //cout<<src<<"  "<<sink<<" flow= "<<curr_flow<<endl;
            }
    }
    return flow;

}


struct node
{
    int dist;
    int cap;

};

node arr[Max];


ll Inp(int N,int R)
{

    int INF=1000000000;

    for(int i=0; i<Max; i++)
        graph[i].clear();

    mem(cap,0);
    mem(f,0);

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {

            if(i==j)
                continue;

            if( abs(arr[i].dist-arr[j].dist)<=R)
            {
                graph[2*i].push_back(2*j-1);
                cap[2*i][2*j-1]=INF;

                graph[2*j].push_back(2*i-1);
                cap[2*j][2*i-1]=INF;


            }
        }

    }

    for(int i=1; i<=N; i++)
    {
        graph[2*i-1].push_back(2*i);
        cap[2*i-1][2*i]=arr[i].cap;

         graph[2*i].push_back(2*i-1);

    }

    for(int i=1; i<=N;i++)
    {
        if(abs(0-arr[i].dist)<=R)
        {
            graph[0].push_back(2*i-1);
            cap[0][2*i-1]=INF;

            graph[2*i-1].push_back(0);
        }
    }

    ll res=dinic(0,2*N);

    return res;


}

int main()
{

    int tc;
    //freopen("input.txt","r",stdin);
    scanf("%d",&tc);

    int INF=1000000000;


    for(int cs=1; cs<=tc; cs++)
    {
        int N;
        int D;
        scanf("%d %d",&N,&D);
        getchar();

        for(int i=1; i<=N; i++)
        {
            char ch;
            int val;
            if(i==1)
            {
                scanf("%c-%d",&ch,&val);

            }
            else
            {
                scanf(" %c-%d",&ch,&val);
            }

            if(ch=='B')
            {
                arr[i].cap=INF;

            }
            else
                arr[i].cap=1;

            arr[i].dist=val;
        }
        arr[N+1].dist=D;
        arr[N+1].cap=INF;

        int lo=0;
        int hi=1200000000;
        int mid;

        while(lo<hi)
        {
            mid=(lo+hi)/2;

            if(Inp(N+1,mid)>=2LL)
            {
                hi=mid;
            }
            else
            {
                lo=mid+1;
            }

        }

        printf("Case %d: %d\n",cs,hi);



    }

    return 0;
}


