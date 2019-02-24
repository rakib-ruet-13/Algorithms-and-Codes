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
#define iread(a) scanf("%d",&a)
#define llread(b) scanf("%lld",&b)
#define dread(d) scanf("%lf",&d)

using namespace std;

typedef long long ll;

struct node
{
    int u,v,w;

    node(int a,int b,int c) { u=a; v=b ;w=c;}

    bool operator < (const node& p) const{return (w<p.w);}

};

ll par[Max];

int ap;

ll Find(ll p)
{
    if(par[p]==p)
        return p;

    return par[p]=Find(par[p]);
}


ll MST_kruskal(vector<node>graph,int n,int air)
{
    ll total_cost=0;

    rep(i,0,n)
     par[i]=i;

   int cnt=0;

   sort( graph.begin() , graph.end());

   int no_of_air=0;

   if(graph.size()!=0)
   rep(i,0,graph.size()-1)
   {
       int u=graph[i].u;
       int v=graph[i].v;
       int weight=graph[i].w;

       ll pu=Find(u);
       ll pv=Find(v);

       if(pu!=pv)
       {
           if(air>weight)
           {
               par[pu]=pv;
               total_cost+=weight;
               cnt++;
           }
       }
   }


   n=n-cnt;
   ap=n;


   return total_cost+(n*air);

}




int main()
{


    int tc;

    iread(tc);

    vector<node>graph;

     rep(cs,1,tc)
     {
         int n,m,a;
         iread(n);
         iread(m);
         iread(a);

        int n1,n2,cst;

        rep(k,1,m)
        {
            scanf("%d %d %d", &n1,&n2,&cst);
            graph.pb(node(n1,n2,cst));
        }

        ll res=MST_kruskal(graph,n,a);


        printf("Case %d: %lld %d\n",cs,res,ap);

       graph.clear();
    }


    return 0;
}

