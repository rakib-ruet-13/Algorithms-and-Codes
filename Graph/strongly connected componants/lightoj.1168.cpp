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

    for(int i=0 ;i<G[u].size(); i++)
    {

        int v=G[u][i];

        if(!visited[v])
        {
            dfs(v);
        }
    }

    stk.push(u);
}


int cnt=0;


int given[Max];


bool flag=0;

int dfs2(int u)
{
    visited[u]=1;

    cnt++;

   // cout<<"u="<<u<<" cnt="<<cnt<<endl;

    for(int i=0 ; i<G[u].size() && i<1 ; i++)
    {

        int v=G[u][i];

        if(visited[v]==1)
        {
            if(flag==0)
                cnt++;

            flag=1;
        }

        if(!visited[v])
        {
            dfs2(v);
        }
    }

    //stk.push(u);
}

int main()
{

    int tc;
    read(tc);

    node=1000;

    REP(cs,tc)
    {
        int child,wish;

        read(child);

        mem(given,0);


        int tot=0;

        REP(k,child)
        {

         read(wish);
        REP(i,wish)
        {
            int u,v;
            read(u);
            read(v);
            G[u+1].pb(v+1);
           // G_rev[v].pb(u);
            tot++;

            given[u+1]=1;
            given[v+1]=1;
        }
        }



    mem(visited,0);


    REP(i,node)
    {
        if(!visited[i] && given[i])
            dfs(i);
    }

    mem(visited,0);
    int mark=0;


    int mx=-11111;
    while(!stk.empty())
    {
        int u=stk.top();
        stk.pop();

       // cout<<"top= "<<u<<endl;

        if(!visited[u])
        {
            flag=0;
            cnt=0;
            dfs2(u);
            //cout<<cnt<<endl;
            mx=max(cnt,mx);
        }
    }

    if(mx==tot+1)
        printf("Case %d: YES\n",cs);
    else
        printf("Case %d: NO\n",cs);



    for(int i=0;i<=node;i++)
    {
        G[i].clear();
        //G_rev[i].clear();
        Componant[i].clear();
    }

    }

}


