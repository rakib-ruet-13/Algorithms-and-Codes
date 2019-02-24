#include<iostream>
#include<bits/stdc++.h>

#define pi acos(-1.0000)
#define LL long long
#define pb(x) push_back(x)
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define uu first
#define vv second

using namespace std;


bool bi_pertite_bfs(int src) ;

int visited[210];
//int par[210];
vector<int>vct[210];

int main()
{
   int node,edge,n1,n2;

   while(cin>>node && node)
   {
       cin>>edge;
       for(int i=0;i<edge;i++)
       {
          cin>>n1>>n2;
          vct[n1].pb(n2);
          vct[n2].pb(n1);
       }
       if(bi_pertite_bfs(0))
        cout<<"BICOLORABLE."<<endl;
       else
        cout<<"NOT BICOLORABLE."<<endl;

        for(int i=0;i<210;i++)
        {
            vct[i].clear();
        }
   }

   return 0;
}

bool bi_pertite_bfs(int src)
{
    mem(visited,-1);

    queue<int>q;
    q.push(src);
    visited[src]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<vct[u].size();i++)
        {
            int v=vct[u][i];
            if(visited[v]==-1)
            {
                visited[v]=1-visited[u];
                q.push(v);

            }
             else
             {
                 if(visited[v]==visited[u])
                    return false;

             }

        }
    }


    return true;

}


