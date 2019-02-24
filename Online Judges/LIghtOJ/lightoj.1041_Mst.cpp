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
    string u,v;
    int w;

    node(string a,string b,int c) { u=a; v=b ;w=c;}

    bool operator < (const node& p) const{return (w<p.w);}

};

map<string,string>par;

string Find(string p)
{
    if(par[p]==p)
        return p;

    return par[p]=Find(par[p]);
}


ll MST_kruskal(vector<node>graph,int n)
{
    ll total_cost=0;

    int cnt=0;

   sort( graph.begin() , graph.end());


   rep(i,0,graph.size()-1)
   {
       string u=graph[i].u;
       string v=graph[i].v;
       int weight=graph[i].w;


       string pu=Find(u);
       string pv=Find(v);

       if(pu!=pv)
       {
           par[pu]=pv;
           total_cost+=weight;
           cnt++;
       }
   }

   if(cnt==n-1)
    return total_cost;
   else
    return -1;

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
        rep(i,1,n)
        {
            string a,b;
            int c;
            cin>>a>>b;
            iread(c);

            par[a]=a;
            par[b]=b;

            graph.pb(node(a,b,c));

        }
        int s=par.size();

        ll res=MST_kruskal(graph,s);



       if(res!=-1)
       printf("Case %d: %lld\n",cs,res);
       else
          printf("Case %d: Impossible\n",cs);


       graph.clear();
       par.clear();
    }


    return 0;
}

