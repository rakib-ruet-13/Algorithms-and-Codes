#include<iostream>
#include<bits/stdc++.h>
#define Max 210
using namespace std;


vector<int>graph[Max];
vector<int>cost[Max];


int visited[Max];
int par[Max];
int res=0;
bool flag=0;

void dfs(int u)
{
    visited[u]=1;

    //cout<<"u="<<u<<endl;

    for(int i=0 ; i<graph[u].size();i++)
    {
        int v=graph[u][i];

        int c=cost[u][i];

        //cout<<"v="<<v<<endl;

        if(par[u]==v)
            continue;


        //cout<<cost[u][i]<<endl;
         if(flag==0 && visited[v]==1)
         {
             if(c>0)
              res+=c;

              flag=1;

         }


        if(visited[v]==0)
        {
             if(cost[u][i]>0)
               res+=cost[u][i];

            par[v]=u;

            dfs(v);

        }


    }

}

  int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        int n;
        scanf("%d",&n);

        int sum=0;

        for(int i=1; i<=n ;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);

            graph[u].push_back(v);
            graph[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(-w);

            sum+=w;
        }

        //cout<<sum<<endl;

        memset(visited,0,sizeof(visited));
        memset(par,-1,sizeof(par));
        res=0;
        flag=0;

        dfs(1);

        //cout<<res<<endl;
        res=abs(res);
        printf("Case %d: %d\n",cs,min(sum-res,res));

        for(int i=0; i<=n;i++)
        {
            graph[i].clear();
            cost[i].clear();
        }
    }


}
