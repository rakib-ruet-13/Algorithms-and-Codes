#include<iostream>
#include<bits/stdc++.h>
#define Max 100000
#define pi acos(-1.000)
#define pb push_back
#define read32(x) scanf("%d",&x)
#define read64(x) scanf("%lld",&x)


using namespace std;

int colour[Max];
int par[Max];
int t;
int finish[Max];
int start[Max];
vector< pair<int,int> > res;

vector<int>graph[Max];

void dfs(int node)
{
    colour[node]=1;
    t=t+1;
    start[node]=t;

    for(int i=0; i<graph[node].size() ; i++)
    {


        if(colour[graph[node][i]]==0)
        {
             par[graph[node][i]]=node;
             dfs(graph[node][i]);
        }

    }

    t=t+1;
    colour[node]=2;
    //cout<<node<<endl;
    res.push_back(make_pair(t,node));


}


bool comp(pair<int,int>a , pair<int,int>b)
{
    return a.first>b.first;
}

int main()
{
    int tc;
    read32(tc);

    for(int cs=1 ; cs<=tc ; cs++ )
    {
         int ver,edge;


         read32(ver);
         read32(edge);

         for(int i=0; i<edge ;i++)
         {
             int u,v;
             read32(u);
             read32(v);

             graph[u].pb(v);
         }

         for(int i=0; i<=ver ; i++)
         {
             colour[i]=0;
         }

         t=0;

         for(int i=1 ;i<=ver ; i++)
         {

             if(colour[i]==0)
                dfs(i);
         }

         sort(res.begin(),res.end(),comp);


         for(int i=0; i<res.size() ; i++ )
         {
             printf(" %d",res[i].second);
         }
         printf("\n");



         for(int i=0; i<=ver ;i++)
            graph[i].clear();
         res.clear();

    }


}
