#include<iostream>
#include<bits/stdc++.h>
#define inf 10010010

using namespace std;

void bfs(int n,int src);

 vector<int>graph[105];

 int l1[105];
 int l2[105];
 int visited[105],parent[105],level[105];


int main()
{


    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {

    int node,edge,n1,n2;
    scanf("%d %d",&node,&edge);

    for(int i=1;i<=edge;i++)
    {
         scanf("%d %d",&n1,&n2);
         graph[n1].push_back(n2);
         graph[n2].push_back(n1);
    }

    int src,des;
    scanf("%d %d",&src,&des);
    bfs(node,src);
    for(int i=0; i<node ;i++)
    {
        l1[i]=level[i];
    }
    bfs(node,des);

      int mx=-111;

      for(int i=0; i<node ;i++)
    {
        l2[i]=level[i];

        mx=max(l1[i]+l2[i],mx);
        graph[i].clear();
    }

    if(mx<inf)
        printf("Case %d: %d\n",cs,mx);
    else
        printf("Case %d: -1\n",cs);

    }


}

void bfs(int n,int src)
{

    queue<int>Q;
    memset(visited,0,sizeof(visited));
    memset(parent,-1,sizeof(parent));

    for(int i=0; i<n; i++)
    {
        level[i]=inf;
    }

    Q.push(src);
    visited[src]=1;
    level[src]=0;

    while(!(Q.empty()))
    {
        int u=Q.front();
        for(int i=0;i<graph[u].size();i++)
        {
           int  v=graph[u][i];

            if(visited[v]==0)
            {
                level[v]=level[u]+1;
                parent[v]=u;
                visited[v]=1;
                Q.push(v);


            }


        }
        Q.pop();


    }


}

