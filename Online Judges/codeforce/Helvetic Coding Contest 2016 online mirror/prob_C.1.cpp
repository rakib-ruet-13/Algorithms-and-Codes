#include<iostream>
#include<bits/stdc++.h>
#define inf 99999999999999
#define pb push_back
#define pi acos(-1.000)
#define all(x) (x.begin(),x.end())
#define VI vector<long long>
#define Max 10010
using namespace std;

typedef long long ll;

bool flag;
vector<int>graph[Max];

int visited[Max];
int par[Max];

void dfs(int u)
{
    visited[u]=1;

    for(int i=0; i<graph[u].size() ;i++)
    {

        int v=graph[u][i];

        if(v==par[u])
            continue;

         if(visited[v]==1)
            {
                flag=false;
                continue;
            }
        par[v]=u;
        dfs(v);

    }

}



int main()
{

    int n,m;
    cin>>n>>m;

    int ind[Max];
    memset(ind,0,sizeof(ind));

    for(int i=1;i<=m ;i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].pb(b);
        graph[b].pb(a);
    }



    bool flag1=true;
    flag=true;

    memset(visited,0,sizeof(visited));
    memset(par,0,sizeof(par));

    dfs(1);



    for(int i=1; i<=n;i++)
    {
       if(visited[i]==0)
        flag1=false;

    }



    if(flag1 && flag)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;


}


