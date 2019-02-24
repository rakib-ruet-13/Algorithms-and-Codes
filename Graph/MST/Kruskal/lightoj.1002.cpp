#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define pb(x) push_back(x)
#define mod (1e9+7)ll
#define pi acos(-1.0000)
#define pii pair<long long,long long>
#define VI vector<long long>
#define CLEAR(a)  memset(a,0,sizeof(a))
#define ALL(x) (x.begin(),x.end())
#define pis pair<int,string>
#define mp make_pair
#define Max 510
#define mem(x,val) memset(x,val,sizeof(x))
#define read(x) freopen("x.txt","r",stdin)
#define write(x) freopen("x.txt","w",stdout)


using namespace std;

typedef long long ll;

ll inf=10000000000;

vector<ll>G[Max];
vector<ll>cost[Max];



struct edge
{
    ll u,v,w;
    edge(ll a,ll b,ll c){ u=a; v=b; w=c;}

    bool operator < (const edge& p) const{ return w<p.w ; }
};

long long par[Max];

ll Find(ll p)
{
    if(p==par[p])
    {
        return p;
    }
    return par[p]=Find(par[p]);
}


ll MST_kruskal(vector<edge>graph,ll n)
{
    ll total_cost=0;
    //int cnt=0;

    sort(graph.begin(),graph.end());

    rep(i,0,n)
   {
       par[i]=i;
   }

    rep(i,0,graph.size()-1)
    {
        ll u=Find(graph[i].u);
        ll v=Find(graph[i].v);

        if(u!=v)
        {
            par[u]=v;

            /***making new graph***/

            G[u].push_back(v);
            G[v].push_back(u);
            cost[u].push_back(graph[i].w);
            cost[v].push_back(graph[i].w);

            total_cost+=graph[i].w;
        }
    }
    return total_cost;
}

ll level[Max];
ll visited[Max];

void dfs(ll u)
{


    visited[u]=1;

    for(int i=0; i<G[u].size(); i++)
    {
        ll v=G[u][i];

        if(visited[v]==0)
        {
            level[v]=max(cost[u][i],level[u]);

            dfs(v);
        }
    }

}

int main()
{
    //freopen("input1.txt","r",stdin);

    int tc;
    vector<edge>graph;

    scanf("%d",&tc);

    rep(cs,1,tc)
    {
        ll node,e;

        scanf("%lld %lld",&node,&e);

        ll n1,n2,weight;

        rep(i,1,e)
        {
            scanf("%lld %lld %lld",&n1,&n2,&weight);

            //cout<<n1<<" "<<n2<<" "<<weight<<endl;

            graph.pb(edge(n1,n2,weight));

        }


        if(e!=0)
        ll res=MST_kruskal(graph,node);
        graph.clear();

        ll src;
        scanf("%lld",&src);


        memset(visited,0,sizeof(visited));





        for(int i=0; i<=node;i++)
            level[i]=inf;

        level[src]=0;
        dfs(src);





        printf("Case %d:\n",cs);

        for(int i=0; i<node ;i++)
        {
            if(level[i]!=inf)
            {
                printf("%lld\n",level[i]);
            }
            else
                printf("Impossible\n");
        }


        for(int i=0; i<=node ;i++)
        {
            G[i].clear();
            cost[i].clear();
            graph.clear();
        }
    }



    return 0;
}

