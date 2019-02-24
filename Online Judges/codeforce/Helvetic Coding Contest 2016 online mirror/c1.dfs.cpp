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

vector<int>graph[Max];
int visited[Max];


void dfs(int u)
{
    visited[u]=1;

    for(int i=0; i<graph[u].size() ;i++)
    {
       if(visited[graph[u][i]]==0)
       {
           dfs(graph[u][i]);
       }

    }

}



int main()
{

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m ;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }



    bool flag1=true;
    memset(visited,0,sizeof(visited));
    dfs(1);


    for(int i=1; i<=n;i++)
    {
       if(visited[i]==0)
        flag1=false;

    }



    if(flag1 && m==n-1)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;


}



