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
#define Max 20010
using namespace std;


struct edge{
    int u,v,cap,flow;
};


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

vector<int>graph[Max+1];
vector<edge>e;
int d[Max+1];
int vis[Max+1];


void addEdge (int a, int b, int cap,int flow) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	graph[a].push_back ((int) e.size());
	e.push_back (e1);
	graph[b].push_back ((int) e.size());
	e.push_back (e2);
}


int arr[110][110];



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
            int id=graph[u][i];
            int to=e[id].v;

            if(d[to]==-1 &&  e[id].flow < e[id].cap )
            {
                q.push(to);
                d[to]=d[u]+1;
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
        int id=graph[src][ind[src]];
          int to=e[id].v;

        if(d[to]!=d[src]+1) continue;

        int curr_flow=dfs(to, min (flow, e[id].cap - e[id].flow),sink);

        if(curr_flow)
        {
           e[id].flow += curr_flow;
           e[id^1].flow -= curr_flow;

            return curr_flow;
        }

    }
    return 0;
}

ll dinic(int src,int sink)
{
    ll flow=0;

    int INF=111111111;

    //cout<<"starting ok"<<endl;

    while(1)
    {
        if(!bfs(src,sink)) break;

       // cout<<"bfs ok"<<endl;

        mem(ind,0);

        while(int curr_flow=dfs(src,INF,sink))
            flow+=curr_flow;
       // cout<<"dfs"<<endl;
    }

    return flow;

}


void Inp()
{
    for(int i=0; i<Max; i++)
        graph[i].clear();
    e.clear();

    int n,m;
    scanf("%d %d",&n,&m);

    char ch;

    int cnt=0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
        arr[i][j]=++cnt;
    }

    int sink= 2*n*m+1;

    int req=0;

    for(int i=1; i<=n; i++)
    {
        getchar();
        for(int j=1; j<=m; j++)
      {
            scanf("%c",&ch);

            //cout<<ch;

            int node= arr[i][j];

            addEdge(node*2-1,node*2,1,0);
            if(ch=='*') { addEdge(0,node*2-1,1,0); req++; }


            if(i==1 || j==1 || i==n || j==m)
              addEdge(node*2,sink,1,0);
            else
            {
                for(int p=0; p<4; p++)
                {
                    int xx=i+dx[p];
                    int yy=j+dy[p];
                    int v=arr[xx][yy];
                    addEdge(node*2,v*2-1,100000,0);
                }
            }
       }


       //cout<<endl;
    }

    int res=dinic(0,sink);

    //cout<<res<<endl;

    if(res==req)
        printf(" yes\n");
    else
        printf(" no\n");

}

int main()
{

    freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc; cs++)
    {
        printf("Case %d:",cs);
        Inp();
    }




    return 0;
}

