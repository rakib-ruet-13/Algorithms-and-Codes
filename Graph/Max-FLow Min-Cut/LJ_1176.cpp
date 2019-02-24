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
#define Max 60
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

map<string,int>mymap;

void Inp()
{
    for(int i=0; i<Max; i++)
        graph[i].clear();

    int node,edge;

    mem(cap,0); mem(f,0);

    int n,k;

    scanf("%d %d",&k,&n);

    string str1,str2;

    for(int i=1; i<=n; i++)
    {
        cin>>str1>>str2;
        graph[6+i].push_back(mymap[str1]);
          graph[6+i].push_back(mymap[str2]);

          cap[6+i][mymap[str1]]=1;
           cap[6+i][mymap[str2]]=1;

        graph[mymap[str1]].push_back(6+i);
         graph[mymap[str2]].push_back(6+i);
    }

    int sink=6+n+1;

    for(int i=1; i<=6; i++)
    {
        graph[i].push_back(sink);
        graph[sink].push_back(i);
        cap[i][sink]=k;
    }

    for(int i=7; i<=6+n; i++)
    {
        graph[0].push_back(i);
        graph[i].push_back(0);

        cap[0][i]=1;

    }

    if(dinic(0,sink)==n)
        printf(" YES\n");
    else
        printf(" NO\n");

}

int main()
{

    int tc;
    scanf("%d",&tc);

    mymap["XXL"]=1;
     mymap["XL"]=2;
      mymap["L"]=3;
       mymap["M"]=4;
        mymap["S"]=5;
         mymap["XS"]=6;


    for(int cs=1; cs<= tc ;cs++)
    {
        printf("Case %d:",cs);
        Inp();

    }




    return 0;
}

