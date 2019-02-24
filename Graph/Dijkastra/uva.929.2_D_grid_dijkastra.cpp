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

#define Max 1000
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define pii pair<ll,ll>
#define pipii pair<int,pii >
#define inf INFINITY

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

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

/***** Nececessary global variables ****/

ll row,col;

pii par[Max][Max];
long long dis[Max][Max];

int graph[Max][Max];

ll dijkastra(pii src,pii n)
{



    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
    {
        dis[i][j]=inf;
        par[i][j].uu=-1;
        par[i][j].vv=-1;



    }
    priority_queue<pipii,vector<pipii>,greater<pipii> >q;

    dis[src.uu][src.vv]=graph[1][1];

    q.push(make_pair(graph[1][1],src));



    while(!q.empty())
    {
        pipii top=q.top();
        q.pop();

        pii u=top.vv;


        if(u==n)
            return dis[u.uu][u.vv];

        ll d=dis[u.uu][u.vv];

        for(int i=0;i<4;i++)
        {
            int x=u.uu+dx[i];
            int y=u.vv+dy[i];

            if(valid(x,y))
            {



            int w=graph[x][y];


            if(d+w<dis[x][y])
            {
                dis[x][y]=d+w;
                par[x][y]=u;

                q.push(make_pair(dis[x][y],pii(x,y)));
            }

            }
        }


    }

    // cout<<dis[row][col]<<endl;
     return -1;





}

int main()
{


  int tc;

  cin>>tc;

   while(tc--)
   {
       cin>>row>>col;
       for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
       {
           scanf("%d",&graph[i][j]);
       }

       pii src,des;
       src=make_pair(1,1);
       des=make_pair(row,col);

       ll ans=dijkastra(src,des);

       cout<<ans<<endl;
   }




}

