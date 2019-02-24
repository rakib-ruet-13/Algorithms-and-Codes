/****
cat: Tarjans algorithm to find strongly connected componanat of a grpah
2016-11-14

*****/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 500010
#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x);
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)
#define mem(x,val) memset(x,val,sizeof(x))

vector<int>graph[Max];
int node,edge;

int par[Max];
int art[Max];
int d[Max];
int visited[Max];
int low[Max];

int t;

vector< pair<int,int> >vct;
stack<int>stk;
vector<int>componant[Max];

void dfs(int u)
{

    t++;
    low[u]=d[u]=t;
    visited[u]=1;
    stk.push(u);

    for(int i=0; i<graph[u].size() ; i++)
    {


        int v=graph[u][i];


        if(visited[v]==1 && v!=par[u])
        {
            low[u]=min(low[u],d[v]);
        }

        else if(visited[v]==0)
        {
            par[v]=u;
            dfs(v);

            low[u]=min(low[u],low[v]);

            if(d[u]< low[v])
            {
              art[u]=1;
              vct.push_back(make_pair(min(u,v),max(u,v)));
            }
        }


    }

    /****keeping the connected componant***/
    if(d[u]==low[u])
    {
        componant[u].push_back(u);

        while(stk.top()!=u)
        {
            int w=stk.top();
            componant[u].push_back(w);
            stk.pop();
        }
        stk.pop();

    }
}



int main()
{

    //freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);

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
                 graph[u].pb(v);
                 graph[v].pb(u);
        }

        mem(d,0);
        mem(par,-1);
        mem(low,0);
        mem(visited,0);

        t=0;

        for(int i=1; i<=node; i++)
        {
            if(visited[i]==0)
                dfs(i);
        }


       printf("Case %d:\n",cs);

       if(vct.size()!=0)
        printf("componats are : \n");

        for(int i=1; i<=node ; i++)
        {
              int sz=componant[i].size();
            if(sz)
            {
                for(int j=0; j<sz ; j++)
                    cout<<componant[i][j]<<" ";
                cout<<endl;
                componant[i].clear();
            }
        }


        printf("bridges are :\n");

        for(int i=0; i<vct.size(); i++)
        {
            printf("%d - %d\n",vct[i].first,vct[i].second);
        }

       vct.clear();


        REP(i,node+2)
        graph[i-1].clear();


    }


    return 0;
}



