/********************************************************/
/********************************************************/
/*************          RAKIB         *******************/
/************       CSE 13, RUET       ******************/
/***********          contact:           ****************/
/******     mail: rakib_cse13@outlook.com     ***********/
/*****           mobile : 01846207019           *********/
/********************************************************/
/********************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/******macros****/

#define Max 200000
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid (x>=1 && x<=col && y>=1 && y<=row)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define pii pair<ll,ll>

/***** useful function ****/

ll power(ll base, ll p){ ll ans=1;if(p==0)return 1;for(ll i=1;i<=p;i++)ans*=base;return ans;}
ll gcd(ll a, ll b){if(a==0)return b;gcd(b,a%b);}

struct node
{
    int ver;
    ll cst;
    node(int x,ll y){ver=x; cst=y;}
    bool operator > (const node& temp) const { return cst>temp.cst;}
};

/***** Nececessary global variables ****/
ll row,col;

int par[Max];
long long dis[Max];

vector<int>graph[Max];
vector<int>cost[Max];

ll dijkastra(int src,int n)
{
    mem(dis,63);


    priority_queue<node,vector<node>, greater<node> >q;
    q.push(node(src,0));
    dis[src]=0;

    while(!q.empty())
    {
        node top=q.top();
        q.pop();

        int u=top.ver;

        //if(u==n)
            //return dis[u];



        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];


            if(dis[u]+cost[u][i]<dis[v])
            {

                dis[v]=dis[u]+cost[u][i];

                par[v]=u;
                q.push(node(v,dis[v]));
            }

        }


    }
    return -1;
}




int main()
{

    int node,edge,src,des;
    vector<int>vct;
    int tc;
    cin>>tc;

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%d %d",&node,&edge);
        mem(par,-1);
         for(int i=0;i<Max;i++)
     {
         graph[i].clear();
         cost[i].clear();
     }

    for(int i=0;i<edge;i++)
    {
        ll n1,n2,c;
        scanf("%d %d %d",&n1,&n2,&c);
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
        cost[n1].push_back(c);
        cost[n2].push_back(c);
    }


    int t;
    cin>>t;
    ll ans=dijkastra(t,node);



     ll inf[1];
            mem(inf,63);


            printf("Case %d:\n",cs);

            for(int i=0;i<node;i++)
            {
                if(dis[i]<inf[0])
                {
                    printf("%lld\n",dis[i]);

                }
                else
                    printf("Impossible\n");
            }

            for(int i=0;i<Max;i++)
            {
                graph[i].clear();
            }

     for(int i=0;i<Max;i++)
     {
         graph[i].clear();
         cost[i].clear();
     }

    }

}

