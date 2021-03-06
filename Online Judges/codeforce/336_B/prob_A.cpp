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
#define rep(i,n) for(i=0;i<n;i++)

/***** useful function ****/

ll power(ll base, ll p){ ll ans=1;if(p==0)return 1;for(ll i=1;i<=p;i++)ans*=base;return ans;}
ll gcd(ll a, ll b){if(a==0)return b;gcd(b,a%b);}
ll dijkastra(int src,int n);

ll row,col;

int par[Max];
long long dis[Max];

vector<pii>graph[Max];



int main()
{

   int tc;
   int cs;





}


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

