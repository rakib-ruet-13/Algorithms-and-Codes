#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void bfs(int n,int src);

 vector<int>graph[1001];

int main()
{

    int node,edge,n1,n2;
    cin>>node>>edge;

    for(int i=1;i<=node;i++)
    {
         cin>>n1>>n2;
         graph[n1].push_back(n2);
         graph[n2].push_back(n1);
    }

    bfs(node,5);

    getchar();
    string str;
    getline(cin,str);


}

void bfs(int n,int src)
{

    queue<int>Q;
    int visited[1001]={0},parent[1001],level[1001];

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

    for(int i=1;i<=n;i++)
    {
        printf("%d to %d distance is= %d\n",src,i,level[i]);
    }


}
