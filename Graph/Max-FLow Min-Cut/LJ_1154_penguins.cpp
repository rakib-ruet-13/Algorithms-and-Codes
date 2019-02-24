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
#define Max 410
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
                //cout<<src<<"  "<<sink<<" flow= "<<curr_flow<<endl;
            }
    }
    return flow;

}


struct node
{
    double x;
    double y;
    int in;
    int cap;

};

double eudis(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);

}
node arr[Max];

void Inp()
{


    int node;
    double rad;

    int INF=111111111;

    sci(node);
    scd(rad);

    for(int i=1; i<=node ; i++)
    {

        scd(arr[i].x);
        scd(arr[i].y);
        sci(arr[i].in);
        sci(arr[i].cap);
           //printf("%f %f %d %d\n",arr[i].x,arr[i].y,arr[i].in,arr[i].cap);
    }


    vector<int>vct;
    for(int sink=1; sink<=node ; sink++)
    {
                  mem(cap,0);
                  mem(f,0);


                for(int i=0; i<Max; i++)
                    graph[i].clear();

                for(int i=1;i<=node; i++)
                {
                    for(int j=i+1; j<=node; j++)
                    {
                        if(i!=j && (eudis(arr[i],arr[j])-rad*rad<=.00000000001))
                        {
                                graph[2*i].push_back(2*j-1);
                                graph[2*j].push_back(2*i-1);

                                cap[2*i][2*j-1]=INF;
                                cap[2*j][2*i-1]=INF;

                                graph[2*i-1].push_back(2*j);
                                graph[2*j-1].push_back(2*i);

                               // cap[2*i][2*j-1]=INF;
                               // cap[2*j][2*i-1]=INF;


                        }
                    }
                }


                ll tot=0;

                for(int i=1; i<=node; i++)
                {
                    graph[0].push_back(2*i-1);
                     graph[2*i-1].push_back(0);



                    cap[0][2*i-1]=arr[i].in;

                    tot+=arr[i].in;
                }


                for(int i=1; i<=node; i++)
                {
                    graph[2*i-1].push_back(2*i);
                    graph[2*i].push_back(2*i-1);

                    cap[2*i-1][2*i]=arr[i].cap;
                }

                ll res=dinic(0,2*sink-1);



                    if(res==tot)
                        vct.push_back(sink);

    }

    if(vct.size()==0)
        printf(" -1\n");
    else
    {
        for(int i=0; i<vct.size(); i++)
        {
            printf(" %d",vct[i]-1);
        }
        printf("\n");
    }

    vct.clear();



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

