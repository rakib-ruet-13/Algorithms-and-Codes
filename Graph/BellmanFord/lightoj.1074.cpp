#include<iostream>
#include<bits/stdc++.h>
#define inf 1000000000
#define Max 1020
using namespace std;

vector<int>G[Max],cost[Max];
vector<int>dist;

bool BellmanFord(int src,int nodes)
{

    dist.clear();

    for(int i=0;i<=nodes ;i++)
        dist.push_back(inf);


    dist[src]=0;


    for(int i=1; i<=nodes-1 ;i++)
    {
        for(int j=1; j<=nodes ; j++)
        {
            for(int k=0; k<G[j].size() ; k++)
            {
                int v=G[j][k];
                int w=cost[j][k];

                dist[v]=min(dist[v], dist[j]+w);
            }
        }
    }


    for(int j=1; j<=nodes ; j++)
    for(int k=0; k<G[j].size() ; k++)
    {
        int v=G[j][k];
        int w=cost[j][k];
        if(dist[v]>dist[j]+w)
        {
            dist[v]=-1;
        }
    }


    return false;

}



int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc; cs++)
    {
        int nodes, edges;

        scanf("%d",&nodes);
        int arr[210];

        for(int i=1; i<=nodes;i++)
            scanf("%d",&arr[i]);

        scanf("%d",&edges);

        for(int i=1; i<=edges ;i++)
        {
            int u,v,w;
            scanf("%d %d",&u,&v);

            w=(arr[v]-arr[u])*(arr[v]-arr[u])*(arr[v]-arr[u]);

            G[u].push_back(v);
            cost[u].push_back(w);


        }

        int src,sink;
        src=1;

        int q;
        scanf("%d",&q);

        printf("Case %d:\n",cs);
        BellmanFord(src,nodes);

         for(int i=0;i<=nodes;i++)
         {
           G[i].clear();
           cost[i].clear();
         }

        for(int i=1;i<=q;i++)
        {

           scanf("%d",&sink);

           if(dist[sink]<3 || dist[sink]>=1600000)
            printf("?\n");
           else
            printf("%d\n",dist[sink]);




        }

    }


}

