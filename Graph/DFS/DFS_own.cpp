#include<iostream>
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define ll long long
#define Max 10010

using namespace std;

struct node
{
    int ver;
    int weight;
};
vector<node>graph[Max];


int cst;

int colour[Max];
int par[Max];

vector<int>station;


void dfs_visit(int u)
{
    colour[u]=1;
    //d[u]=Time;


    for(int i=0;i<graph[u].size();i++)
    {
        int v = graph[u][i].ver;
       // cout<<v<<"  "<<graph[u][i].weight<<endl;
        if(colour[v]==0)
        {
            par[v]=u;
           //cout<<v<<"  "<<graph[u][i].weight<<endl;
           // cout<<cst<<endl;
            if(cst+graph[u][i].weight>5)
            {
                cst=0;
                station.pb(par[v]);
            }
            else
                cst+=graph[u][i].weight;
            //cout<<v<<endl;

            dfs_visit(v);
        }
    }
    colour[u]=2;




}



int main()
{
    freopen("input.txt","r",stdin);


    int node, edge;

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        cst=0;
        memset(colour,0,sizeof(colour));

        scanf("%d %d",&node,&edge);

        for(int i=0 ;i<edge; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);

            struct node temp;
            temp.ver=v;
            temp.weight=w;

            graph[u].pb(temp);

        }

        station.pb(1);
        dfs_visit(1);

        printf("Case %d:\n",cs);
        printf("Required stations are : \n");
        for(int i=0;i<station.size() ;i++)
        {
            printf("%d ",station[i]);
        }
        printf("\n");

        station.clear();

        for(int i=0 ;i<Max ;i++)
        {
            graph[i].clear();

        }
    }




    return 0;
}
