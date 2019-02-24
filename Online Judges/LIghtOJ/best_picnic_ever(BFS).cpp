#include<iostream>
#include<bits/stdc++.h>
#define Max 1005
#define pb(x) push_back(x)
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define pii pair<int,int>
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;

int visited[Max+1];
//int level[Max+1];
//int par[Max+1];
vector<int>graph[Max+1];

int bfs(int src,int des)
{
    mem(visited,0);
    //mem(level,0);
    int cnt=0;
    queue<int>q;
    q.push(src);
    visited[src]=1;
    //level[src]=0;
    //par[src]=src;
    cnt++;

    while(!q.empty())
    {
        int top=q.front(); q.pop();
        for(int i=0; i<graph[top].size(); i++)
        {
            int u=graph[top][i];

            if(visited[u]==0)
            {
                cnt++;

                visited[u]=1;
                //par[u]=src;
                //level[u]=level[top]+1;
                q.push(u);
            }

        }
    }
    return cnt;
}


int main()
{
    int tc,k;
    vector<int>vct;
   // freopen("input.txt","r",stdin);

    scanf("%d",&tc);


    for(int cs=1 ;cs<=tc ;cs++)
    {
        int k;
        int node;
        int edge;
        int n1,n2;
        scanf("%d %d %d",&k,&node,&edge);

        for(int i=0;i<k;i++)
        {
            int p;
            scanf("%d",&p);
            vct.push_back(p);
        }


        for(int i=0; i<edge ;i++)
        {


            scanf("%d %d",&n1,&n2);
            graph[n1].pb(n2);
        }


        int mn=11111111;




       for(int i=1; i<=k ;i++)
      {
         mn=min(mn,bfs(vct[i-1],100));
      }

      for(int i=1; i<=node ; i++)
      {
          graph[i].clear();
      }
      vct.clear();

      printf("Case %d: %d\n",cs,mn);
    }





}

