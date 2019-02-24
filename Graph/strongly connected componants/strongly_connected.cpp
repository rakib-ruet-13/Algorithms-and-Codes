#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 100010
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



int main()
{

    int tc;
    read(tc);

    REP(cs,tc)
    {
        read(node);
        read(edge);

        REP(i,edge)
        {
            int u,v;
            read(u);
            read(v);

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
            printf("%d ",Componant[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<=node;i++)
    {
        G[i].clear();
        G_rev[i].clear();
        Componant[i].clear();
    }

    }

}

