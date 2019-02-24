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

#define Max 20010
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

vector<pii>graph[Max];


ll dijkastra(int src,int n)
{

    mem(dis,63);
    mem(par,-1);
    priority_queue<pii,vector<pii>,greater<pii> >q;

    q.push(pii(0,src));

    dis[src]=0;

    while(!q.empty())
    {
        pii top=q.top();
        q.pop();

        int u=top.vv;

        if(u==n)
            return dis[u];

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].uu;
            int w=graph[u][i].vv;

            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                par[v]=u;
                q.push(pii(dis[v],v));
            }
        }


    }

    return -1;



}

int main()
{

    int node,edge;
    int src,des;
    int inf[1];
    mem(inf,63);

    int tc;
    cin>>tc;

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%d %d",&node,&edge);
           scanf("%d %d",&src,&des);

        for(int i=0;i<edge;i++)
        {
            int n1,n2,w;

            scanf("%d %d %d",&n1,&n2,&w);

            graph[n1].push_back(pii(n2,w));
            graph[n2].push_back(pii(n1,w));
        }

        printf("Case #%d: ",cs);





            int res=dijkastra(src,des);
            if(res!=-1)
            {
                cout<<res<<endl;
            }
            else
                cout<<"unreachable"<<endl;

            for(int i=0;i<Max;i++)
            {
                graph[i].clear();
            }



    }





}

