#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int>graph[1010];



int colour[1010];
int visited[1000];
int self[1010];
int bkedge[1010];

vector<int>p;

void dfs(int u)
{
    colour[u]=1;

    for(int i=0; i<graph[u].size() ; i++)
    {
        if(colour[graph[u][i]]==0)
        {
            dfs(graph[u][i]);
        }
        else
        {
            bkedge[graph[u][i]]=1;
        }
    }
    colour[u]=2;

}

int main()
{
    int node;

    while(cin>>node && node)
    {
        int root;

        memset(self,0,sizeof(self));

        for(int i=0; i<=node; i++)
            graph[i].clear();

        while(cin>>root && root!=0)
        {

            int u;

          while(cin>>u && u!=0)
          {
            graph[root].push_back(u);
          }
        }



        int q;
        cin>>q;

        for(int i=0;i<q; i++)
        {
            int test;
            cin>>test;


            memset(colour,0,sizeof(colour));
            memset(bkedge,0,sizeof(bkedge));

            dfs(test);

            vector<int>res;


            for(int i=1; i<=node ; i++)
            {
                if(test!=i)
                {

                    if(colour[i]==0)
                  {
                    res.push_back(i);
                  }
                }
                  else
                  {
                      if(bkedge[i]==0)
                      {
                          res.push_back(i);
                      }
                  }

            }



            cout<<res.size();

            for(int i=0; i<res.size(); i++)
            {
                cout<<" "<<res[i];
            }

            cout<<endl;

            res.clear();

            memset(colour,0,sizeof(colour));
        }


    }


}
