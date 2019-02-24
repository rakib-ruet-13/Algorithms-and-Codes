#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 20010
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

int LF[Max];


int cnt=0;

int dfs_add_comp(int u,int mark)
{
    visited[u]=1;

    int temp=0;

        //cnt++;

    for(int i=0;i<G[u].size() ;i++)
    {
        int v=G[u][i];

        if(!visited[v])
            {
                temp++;
                dfs_add_comp(v,mark);
            }
    }

    if(temp==0)
        cnt++;

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
            G_rev[u].pb(v);
        }



    mem(visited,0);


    REP(i,node)
    {
        if(!visited[i])
            dfs(i);
    }

    mem(visited,0);
    int mark=0;
    int res=0;

    while(!stk.empty())
    {
        int u=stk.top();
        stk.pop();

        if(!visited[u])
        {
            mark++;
            cnt=0;
            dfs_add_comp(u,mark);
            res+=cnt-1;
        }
    }

    res+=mark;


    if(node==1)
        res=0;

   printf("Case %d: %d\n",cs,res);

    for(int i=0;i<=node;i++)
    {
        G[i].clear();
        G_rev[i].clear();
        Componant[i].clear();
    }

    }

}


