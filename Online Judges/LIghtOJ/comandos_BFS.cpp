#include<iostream>
#include<bits/stdc++.h>
#define Max 105
#define pb(x) push_back(x)
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define pii pair<int,int>
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;

int visited[Max+1];
int level[Max+1];
vector<int>graph[Max+1];

int bfs(int src,int des)
{
    mem(visited,0);
    mem(level,0);

    queue<int>q;
    q.push(src);
    visited[src]=1;
    level[src]=0;

    while(!q.empty())
    {
        int top=q.front(); q.pop();

        if(top==des)
            return level[top];

        for(int i=0; i<graph[top].size(); i++)
        {
            int u=graph[top][i];

            if(visited[u]==0)
            {

                visited[u]=1;
                level[u]=level[top]+1;
                q.push(u);
            }

        }
    }
    return -1;
}


int main()
{
    int tc;
    //freopen("input.txt","r",stdin);

    scanf("%d",&tc);

    for(int cs=1 ;cs<=tc ;cs++)
    {
        int node;
        int edge;
        int n1,n2;
        scanf("%d %d",&node,&edge);

        for(int i=0; i<edge ;i++)
        {


            scanf("%d %d",&n1,&n2);
             n1++;
             n2++;

            graph[n1].pb(n2);
            graph[n2].pb(n1);
        }

       int src,des;
       scanf("%d %d",&src,&des);
       src++;
       des++;

       int lvl[Max+1];

       bfs(src,101);

       for(int i=1; i<=node ;i++)
      {

          lvl[i]=level[i];
      }

      int mx=-1;

      int n;
      for(int i=1; i<=node ;i++)
      {
        n=bfs(i,des);
        n=n+lvl[i];
        mx=max(mx,n);
      }

      for(int i=1; i<=node ; i++)
      {
          graph[i].clear();
      }

      printf("Case %d: %d\n",cs,mx);
    }





}
