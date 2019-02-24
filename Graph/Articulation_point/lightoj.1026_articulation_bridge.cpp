/****
light oj 1026
cat: Articulation bridge
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

void dfs(int u)
{

    t++;
    low[u]=d[u]=t;
    visited[u]=1;

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
}

bool comp(pair<int,int>a, pair<int,int>b)
{
    if(a.first==b.first)
        return a.second<b.second;
    else
        return a.first<b.first;
}


int main()
{

    //freopen("output.txt","w",stdout);

    int tc;
    read(tc);
    int u,v;

    REP(cs,tc)
    {
        read(node);
        //read(edge);

        REP(i,node)
        {
            int b;
            scanf("%d (%d)",&u,&b);

            while(b--)
            {
                scanf("%d",&v);
                 graph[u].pb(v);
                 graph[v].pb(u);
            }

        }

        mem(d,0);
        mem(par,-1);
        mem(low,0);
        mem(visited,0);

        t=0;

        for(int i=0; i<node; i++)
        {
            if(visited[i]==0)
                dfs(i);
        }


       sort(vct.begin(),vct.end(),comp);


       printf("Case %d:\n",cs);

       if(vct.size()!=0)
        printf("%d critical links\n",vct.size());

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


