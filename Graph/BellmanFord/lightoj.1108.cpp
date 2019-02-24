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


void dfs(int u)
{
    colour[u]=1;

    for(int i=0 ; i< G[u].size() ;i++)
    {
        int v=G[u][i];

        if(colour[v]==0)
            dfs(v);
    }

}



int main()
{
    int tc;
    scanf("%d",&tc);

    int nodes,edges;

    for(int cs=1 ; cs<= tc ; cs++)
    {
        scanf("%d %d",&nodes,&edges);

        for(int i=1; i<=edges ;i++)
        {
            int u,v,w;

            scanf("%d %d %d",&u,&v,&w);

            G[v+1].push_back(u+1);
            cost[v+1].push_back(w);
        }

        for(int i=1;i<=nodes;i++)
        {
            G[0].push_back(i);
           //  G[i].push_back(0);
            cost[0].push_back(0);
           // cost[i].push_back(0);
        }

        memset(visited,0,sizeof(visited));


        if(BellmanFord(0,nodes)== false )
        {
            printf("Case %d: impossible\n",cs);
        }
        else
        {
             printf("Case %d:",cs);

            memset(colour,0,sizeof(colour));

            for(int i=1;i<=nodes;i++)
            {
                if(visited[i]==1 && colour[i]==0)
                {
                    dfs(i);
                }

            }


            for(int i=1;i<=nodes;i++)
            {
               if(colour[i]==1)
                printf(" %d",i-1);

            }
            printf("\n");
        }

        for(int i=0; i<=nodes ;i++)
        {
            G[i].clear();
            cost[i].clear();
        }

    }



}
