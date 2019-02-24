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

#define Max 200001
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid (x>=1 && x<=col && y>=1 && y<=row)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define pii pair<ll,ll>

struct node
{
    int ver;
    ll cst;
    node(int x,ll y){ver=x; cst=y;}
    bool operator > (const node& temp) const { return cst>temp.cst;}
};


ll inf;



ll row,col;

int par[Max];
long long dis[Max];

vector<ll>graph[Max];
vector<ll>cost[Max];

ll dijkastra(ll src,ll n)
{


    for(int i=0; i<=n ;i++)
        dis[i]=inf;


    priority_queue<node,vector<node>, greater<node> >q;
    q.push(node(src,0));
    dis[src]=0;

    while(!q.empty())
    {
        node top=q.top();
        q.pop();

        int u=top.ver;




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




int allowed[Max];


int main()
{

    int node,edge,k;
    vector<int>vct;

    inf=10000000000000000;

     cin>>node>>edge>>k;

    for(int i=0;i<edge;i++)
    {
        ll n1,n2,c;
        scanf("%lld %lld %lld",&n1,&n2,&c);
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
        cost[n1].push_back(c);
        cost[n2].push_back(c);
    }

    memset(allowed,1,sizeof(allowed));

    for(int i=1; i<=k ;i++)
    {
        int ph;
        cin>>ph;
        allowed[ph]=0;
    }


    for(int i=1; i<=node ;i++)
    {
        if(allowed[i])
        {

          graph[i].push_back(0);
          graph[0].push_back(i);
          cost[i].push_back(0);
          cost[0].push_back(0);
        }

    }



    ll ans=dijkastra(0,node);

    ll resp=inf;

    for(int i=1; i<=node ;i++)
    {

        if(dis[i]>0 && dis[i]!=inf && allowed[i]==0)
      {
        resp=min(resp,dis[i]);
      }

      //cout<<dis[i]<<endl;
    }

    if(resp!=inf)
        cout<<resp<<endl;
    else
        cout<<-1<<endl;
}
