#include<iostream>
#include<bits/stdc++.h>
#define inf 2000000000000000L
#define Max 1020
using namespace std;

vector<long long int>G[Max],cost[Max];
vector<long long int>dist;

bool BellmanFord(long long int src,long long int nodes)
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
                long long int v=G[j][k];
                long long int w=cost[j][k];

                dist[v]=min(dist[v], dist[j]+w);
            }
        }
    }


    for(int j=0; j<=nodes ; j++)
    for(int k=0; k<G[j].size() ; k++)
    {
        long long int v=G[j][k];
        long long int w=cost[j][k];

        if(dist[v]>dist[j]+w)
            return true;
    }


    return false;

}




int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc; cs++)
    {
        long long int nodes, edges,p;

        scanf("%lld %lld %lld",&nodes,&edges,&p);

        for(int i=1; i<=edges ;i++)
        {
            long long int u,v,I,e;
            scanf("%lld %lld %lld %lld",&u,&v,&I,&e);

            G[u+1].push_back(v+1);

            cost[u+1].push_back( p*e-I);

        }



        for(int i=1; i<=nodes ; i++)
        {
            G[0].push_back(i);
            cost[0].push_back(0);
        }

        if(BellmanFord(0,nodes))
        {
            printf("Case %d: YES\n",cs);

        }
        else
            printf("Case %d: NO\n",cs);

        for(int i=0;i<=nodes;i++)
        {
             G[i].clear();
             cost[i].clear();

        }

    }


}

