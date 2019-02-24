#include<iostream>
#include<bits/stdc++.h>
#define inf 400000000
#define Max 1210
#define rep(i,a,b) for(int i=a; i<=b ; i++)
#define pb push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;

int graph[Max][Max];
int next[Max][Max];


void floyed_warshall(int node)
{
    for(int i=1;i<=node ;i++)
        for(int j=1;j<=node;j++)
           for(int k=1;k<=node;k++)
    {
        if(graph[i][j]>graph[i][k]+graph[k][j])
        {
            graph[i][j]=graph[i][k]+graph[k][j];
            next[i][j]=next[i][k];
        }

    }

}

int find_path(int src,int des)
{
    vector<int>path;

    long long res=0;

    int s=src;
    int d=des;

    while(src!=des)
    {
        src=next[src][des];
        path.pb(src);
    }


    for(int i=0 ;i<path.size() ; i++ )
    {
        res=res+graph[s][path[i]];
        s=path[i];
    }

    if(res>=inf)
        return -1;
    else
        return res;
}

int main()
{
    int node, edge;

    freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
       scanf("%d %d",&node,&edge);

       for(int i=0;i<=node ; i++)
            for(int j=0; j<=node ; j++)
       {
           if(i==j)
            graph[i][j]=0;
           else
            graph[i][j]=inf;

           next[i][j]=j;
       }

       for(int i=1; i<=edge ;i++)
       {
           int u,v,cost;
           scanf("%d %d %d",&u,&v,&cost);
           graph[u][v]=cost;
       }

       floyed_warshall(node);

       int q,src,des;
       scanf("%d",&q);


       for(int i=0 ;i<q; i++)
       {
           scanf("%d %d",&src,&des);
           printf("%d\n",find_path(src,des));
       }

    }
}

