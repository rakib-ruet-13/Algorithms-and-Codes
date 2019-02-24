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

ll Find(ll p)
{
    if(par[p]==p)
        return p;

    return par[p]=Find(par[p]);
}


ll MST_kruskal(vector<node>graph,int n)
{
    ll total_cost=0;
    rep(i,0,n)
     par[i]=i;

   sort( graph.begin() , graph.end());


   rep(i,0,graph.size()-1)
   {
       int u=graph[i].u;
       int v=graph[i].v;
       int weight=graph[i].w;

       ll pu=Find(u);
       ll pv=Find(v);

       if(pu!=pv)
       {
           par[pu]=pv;
           total_cost+=weight;
       }
   }

   return total_cost;

}



ll MST_kruskal2(vector<node>graph,int n)
{
    ll total_cost=0;
    rep(i,0,n)
     par[i]=i;

   sort( graph.begin() , graph.end());

   reverse( graph.begin() , graph.end());


   rep(i,0,graph.size()-1)
   {
       int u=graph[i].u;
       int v=graph[i].v;
       int weight=graph[i].w;

       ll pu=Find(u);
       ll pv=Find(v);

       if(pu!=pv)
       {
           par[pu]=pv;
           total_cost+=weight;
       }
   }

   return total_cost;

}

int main()
{


    int tc;

    iread(tc);

    vector<node>graph;

    rep(cs,1,tc)
    {
        int n;
        iread(n);
        do
        {
            int a,b,c;
            iread(a);
            iread(b);
            iread(c);


            if(c==0)
                break;

            graph.pb(node(a,b,c));

        }while(1);

        ll res=MST_kruskal(graph,n);
        //cout<<res<<endl;

        ll res1=MST_kruskal2(graph,n);
        //cout<<res1<<endl;

        res=res+res1;

       if(res%2==0)
       printf("Case %d: %lld\n",cs,res/2);
       else
        printf("Case %d: %lld/2\n",cs,res);

       graph.clear();
    }


    return 0;
}
