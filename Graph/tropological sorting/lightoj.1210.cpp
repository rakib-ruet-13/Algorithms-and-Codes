#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 50000
#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x);
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x)  printf("%lld\n",x)
#define mem(x,val) memset(x,val, sizeof(x))

vector<int>G[Max];
vector<int>G_rev[Max];
vector<int>Componant[Max];

int node,edge;
int par[Max];

int visited[Max];

stack<int>stk;

int dfs(int u)
{
    visited[u]=1;

    for(int i=0 ;i<G[u].size() ; i++)
    {

        int v=G[u][i];

        if(!visited[v])
        {
            dfs(v);
        }
    }

    stk.push(u);
}

int dfs_add_comp(int u,int mark)
{
    visited[u]=1;
    Componant[mark].pb(u);

    for(int i=0;i<G_rev[u].size() ;i++)
    {
        int v=G_rev[u][i];

        if(!visited[v])
            dfs_add_comp(v,mark);
    }

}



int ind[Max];
int out[Max];


int main()
{

    int tc;
    read(tc);
    int u,v;


    REP(cs,tc)
    {
        read(node);
        read(edge);

        REP(i,edge)
        {
            scanf("%d %d",&u,&v);
                 G[u].pb(v);
                 G_rev[v].pb(u);
        }



    mem(visited,0);


    REP(i,node)
    {
        if(!visited[i])
            dfs(i);
    }

    mem(visited,0);
    int mark=0;

    while(!stk.empty())
    {
        int u=stk.top();
        stk.pop();

        if(!visited[u])
        {
            mark++;
            dfs_add_comp(u,mark);
        }
    }

    for(int i=1;i<=mark ;i++)
    {
        for(int j=0; j<Componant[i].size(); j++)
        {

            int v=Componant[i][j];
            par[v]=i;
        }
    }

       int no_of_com=mark;

      // cout<<"componant no= "<<no_of_com<<endl;


        int in,ot;

        in=ot=0;

        memset(ind,0,sizeof(ind));
        memset(out,0,sizeof(out));

        for(int i=1 ;i<=node ; i++)
        {
            for(int j=0 ; j<G[i].size() ; j++)
            {
                int v=G[i][j];

                if(par[i]!=par[v])
                {
                    out[par[i]]++;
                    ind[par[v]]++;

                }
            }
        }


       for(int i=1; i<=mark ; i++)
       {

               if(!ind[i])
               in++;
               if(!out[i])
                ot++;
       }



        if (no_of_com>1)
            printf("Case %d: %d\n",cs,max(in,ot));
        else
            printf("Case %d: 0\n",cs);

        REP(i,node+5)
        {
            G[i-1].clear();
            G_rev[i-1].clear();
            Componant[i-1].clear();
        }

    }


    return 0;
}




