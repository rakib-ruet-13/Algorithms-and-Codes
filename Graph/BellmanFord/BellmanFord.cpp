#include<iostream>
#include<bits/stdc++.h>
#define Max 1020
#define inf 2100000000

using namespace std;


vector<int>G[Max];
vector<int>cost[Max];
vector<int>dist;

int visited[Max];
int colour[Max];

bool BellmanFord(int src,int nodes)
{

    dist.clear();

    for(int i=0;i<=nodes ;i++)
        dist.push_back(inf);


    dist[src]=0;


    for(int i=0; i<=nodes-1 ;i++)
    {
        for(int j=0; j<=nodes ; j++)
        {
            for(int k=0; k<G[j].size() ; k++)
            {
                int v=G[j][k];
                int w=cost[j][k];

                dist[v]=min(dist[v], dist[j]+w);
            }
        }
    }

    int cnt=0;

    for(int j=0; j<=nodes ; j++)
    for(int k=0; k<G[j].size() ; k++)
    {
        int v=G[j][k];
        int w=cost[j][k];

        //cout<<dist[4]<<" "<<dist[5]<<endl;

        if(dist[v]>dist[j]+w)
           {
              dist[v]=dist[j]+w;
              visited[v]=1;
              cnt++;
           }
    }

    if(cnt>0)
        return true;

    return false;

}





int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc; cs++)
    {
        int nodes, edges;

        scanf("%d %d",&nodes,&edges);

        for(int i=1; i<=edges ;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);

            G[u].push_back(v);
            G[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);

        }

        int src,sink;
        scanf("%d",&src);
        scanf("%d",&sink);

        if(BellmanFord(src,nodes))
        {
            printf("Case %d: Negative cycle detected!!!!\n",cs);

        }
        else
            printf("Case %d: %d\n",cs,dist[sink]);

        for(int i=0;i<=nodes;i++)
        {
             G[i].clear();
             cost[i].clear();

        }

    }


}
