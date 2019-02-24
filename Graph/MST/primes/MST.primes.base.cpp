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
using namespace std;

typedef long long ll;

struct node
{
    ll w,v;
    node(ll a,ll b){v=a; w=b; }
    bool operator > (const node& p) const{ return w>p.w; }
};

vector<long long> graph[Max+1],cost[Max+1],vertices;

bool visited[Max+1];

ll MST_primes(int src,int n)
{
   // int cnt=0;

    CLEAR(visited);
    priority_queue< node, vector<node> , greater<node> >q;
    ll total_cost=0,c;

    rep(i,1,n-1)
    {


        visited[src]=true;
        //vertices.pb(src);

        rep(k,0,graph[src].size()-1)
        {
            //cnt++;
           q.push(node(graph[src][k],cost[src][k]));
        }

        do
        {
            node t=q.top();
            src=t.v;
            c=t.w;
            q.pop();
        }while(visited[src]==true && !q.empty());

        total_cost+=c;

    }

    //cout<<cnt<<endl;

    return total_cost;
}

int main()
{

    freopen("input1.txt","r",stdin);

    int n,e;

    int tc;
    scanf("%d",&tc);

    rep(cs,1,tc)
    {
        scanf("%d %d",&n,&e);

        rep(i,1,e)
        {
            ll n1,n2,weight;
            scanf("%lld %lld %lld",&n1,&n2,&weight);
            graph[n1].pb(n2);
            graph[n2].pb(n1);

            cost[n1].pb(weight);
            cost[n2].pb(weight);
        }


        ll res=MST_primes(1,n);

        printf("Case %d: %lld\n",cs,res);

        for(int i=0 ;i<=n;i++)
        {
            graph[i].clear();
            cost[i].clear();
        }
    }
}

