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
#define Max 100010
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

ll MST_kruskal(vector<edge>graph,int n)
{
    ll total_cost=0;
    //int cnt=0;
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
            cnt++;
        }
    }

    //cout<<cnt;
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

        ll sum=0;
        for(int i=1; i<=node ;i++)
        {
            for(int j=1; j<=node ; j++)
            {
                int p;
                scanf("%d",&p);

                sum+=p;

                if(i!=j && p!=0)
                  graph.pb(edge(i,j,p));
            }
        }


        cnt=0;
        ll res=0;
        if(graph.size()!=0)
        res=MST_kruskal(graph,node);

        bool flag=1;

        if(cnt!=node-1)
            flag=0;
        //cout<<cnt<<endl;
        if(flag)
        printf("Case %d: %lld\n",cs,sum-res);
        else
        printf("Case %d: -1\n",cs);
        graph.clear();


    }



    return 0;
}

