#include<iostream>
#include<bits/stdc++.h>
#define inf 99999999999999
#define pb push_back
#define pi acos(-1.000)
#define all(x) (x.begin(),x.end())
#define VI vector<long long>
#define Max 1001000
using namespace std;

typedef long long ll;

int mx;
vector<int>graph[Max];
int ind[Max];
int visited[Max];
int level[Max];


int bfs(int src)
{
    memset(visited,0,sizeof(visited));

    visited[src]=1;
    level[src]=0;

    int m=0;

    queue<int>q;

    q.push(src);

    while(!q.empty())
    {

        int u=q.front();
        q.pop();

        for(int i=0;i<graph[u].size() ;i++)
        {
            int v=graph[u][i];

            if(!visited[v])
            {
                q.push(v);
                level[v]=level[u]+1;
                visited[v]=1;
                m=max(m,level[v]);
            }
        }

    }
    return m;


}


int main()
{

    int n,m;
    cin>>n>>m;


    memset(ind,0,sizeof(ind));

    for(int i=1;i<=m ;i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].pb(b);
        graph[b].pb(a);

        if(a!=b)
        {
         ind[a]++;
         ind[b]++;
        }
    }


    int res=bfs(1);
    int src;

    for(int i=1;i<=n ;i++)
    {
        if(level[i]==res)
            src=i;
    }

    cout<<bfs(src)<<endl;

}



