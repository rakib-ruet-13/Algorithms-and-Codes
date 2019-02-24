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
#define Max 220
#define mem(x,val) memset(x,val,sizeof(x))
#define read(x) freopen("x.txt","r",stdin)
#define write(x) freopen("x.txt","w",stdout)

using namespace std;

typedef long long ll;



struct edge
{
    int u,v,w;
    edge(int a,int b,int c){ u=a; v=b; w=c;}

    bool operator < (const edge& p) const{ return w<p.w ; }
};


vector<edge>graph1;

long long par[Max];

ll Find(ll p)
{
    if(p==par[p])
    {
        return p;
    }
    return par[p]=Find(par[p]);
}

int cnt;

int mx=-11111111;

ll MST_kruskal(vector<edge>graph,int n)
{
    ll total_cost=0;

    if(graph.size()!=0)
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
            total_cost+=graph[i].w;
            mx=max(mx,graph[i].w);

            graph1.pb(edge(u,v,graph[i].w));
            graph1.pb(edge(v,u,graph[i].w));
            cnt++;
        }
    }
    return total_cost;
}

int main()
{
    //freopen("input1.txt","r",stdin);

    int tc;
    vector<edge>graph;

    scanf("%d",&tc);

    rep(cs,1,tc)
    {
        int node,e;

        scanf("%d",&node);
        scanf("%d",&e);

        printf("Case %d:\n",cs);
        mx=-11111111;

        for(int ww=0; ww<e; ww++)
        {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);


            graph.pb(edge(a,b,w));
            graph.pb(edge(b,a,w));




           cnt=0;

          ll res=0;
             res=MST_kruskal(graph,node);

             graph.clear();
             graph=graph1;
             graph1.clear();

         if(cnt!=node-1)
             res=-1;

           printf("%lld\n",res);
        }

        graph.clear();


    }



    return 0;
}

