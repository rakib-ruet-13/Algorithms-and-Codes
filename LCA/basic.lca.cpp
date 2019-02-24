#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define rep(i,a,b) for(int i=a; i<=b;i++)
#define inf 10e14
#define read(x) scanf("%lld",&x);
#define Max 100001

using namespace std;


vector<ll>graph[Max];

ll lvl[Max];
ll par[Max];
ll ind[Max];

ll PT[Max][17];

void dfs(ll u,ll L,ll p)
{
     lvl[u]=L;
     par[u]=p;

    for(int i=0;i<graph[u].size() ;i++)
    {
         ll m;
         m=graph[u][i];
         dfs(m,L+1,u);
    }
}


void LCA_init(int n)
{
    rep(i,1,n)
    PT[i][0]=par[i];

    for(int j=1; 1<<j <n ; j++)
        for(int i=1;i<n;i++)
    {

        if( PT[i][j-1]!=-1)
            PT[i][j]=PT[PT[i][j-1]][j-1];
    }
}


ll LCA_query(ll p,ll q)
{

    if(lvl[p]<lvl[q])
        swap(p,q);

    ll log=1;
    while(1<<log <lvl[p])
        log++;

    if(1<<log >lvl[p])
        log--;


    for(int i=log ; i>=0 ;i--)
    {
        if( lvl[p]- (1<<i) >=lvl[q])
             p=PT[p][i];
    }


    if(p==q)
        return p;


    for(int i=log ; i>=0 ;i--)
    {
        if(PT[p][i]!=-1 && (PT[p][i]!=PT[q][i]))
        {
            p=PT[p][i];
            q=PT[q][i];
        }
    }
    return par[p];

}


int main()
{

    //freopen("input.txt","r",stdin);
    ll tc;

    read(tc);

    rep(cs,1,tc)
    {
        ll node,edge;

        read(node);
        read(edge);



        memset(ind,0,sizeof(ind));

        rep(i,1,edge)
        {
            ll u,v;
            read(u);
            read(v);

            ind[v]++;

            graph[u].pb(v);
        }

        ll src;

        rep(i,1,node)
        if(ind[i]==0)
        {
            src=i;
            break;
        }

        ll log=1;
        do
        {
           log++;
        }
        while(1<<log < node);





        rep(i,0,node)
         rep(j,0,log)
         {
             PT[i][j]=-1;
         }

        rep(i,0,node)
         par[i]=-1;



        dfs(src,0,-1);
        LCA_init(node);



       ll q;
       read(q);

       printf("Case %d:\n",cs);

       while(q--)
       {
           ll p,q;
           read(p);
           read(q);

           printf("%lld\n",LCA_query(p,q));
       }

       for(int i=0;i<=node;i++)
        graph[i].clear();



    }


    return 0;
}
