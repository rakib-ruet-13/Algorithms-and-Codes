#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 2010000

int visited[Max];
vector<int>graph[Max];
vector<int>vct;

int b,c;

int n;

int cnt;

vector<int>vct1,vct2;



bool bi_pertite_bfs(int src)
{

    //vct1.clear();
   // vct2.clear();
    queue<int>q;
    q.push(src);
    visited[src]=1;

    vct1.push_back(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(visited[v]==-1)
            {
                visited[v]=1-visited[u];
                if(visited[v]==1)
                    vct1.push_back(v);
                else
                    vct2.push_back(v);

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






int main()
{



        cin>>n;

        for(int i=0;i<Max;i++)
            graph[i].clear();

            memset(visited,-1,sizeof(visited));

        //memset(colour,-1,sizeof(colour));

        int a;

        scanf("%d",&a);

        int src;

        for(int i=0;i<a;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);

            graph[u].push_back(v);
            graph[v].push_back(u);

            if(i==0)
                src=u;


        }

       // cout<<src<<endl;
        bool flag=true;



        for(int i=1;i<=n;i++)
        {

            if(graph[i].size()==0 || (visited[i]!=-1))
                continue;

            if(bi_pertite_bfs(i)==false)
            {
                cout<<-1<<endl;
                return 0;
            }


        }


               if(vct1.size()>=1 && vct2.size()>=1)
                {

                 if(vct1.size()<vct2.size())
                 {
                     cout<<vct1.size()<<endl;
                     sort(vct1.begin(),vct1.end());
                     for(int i=0;i<vct1.size() ;i++)
                     {
                         if(i==0)
                            cout<<vct1[i];
                         else
                            cout<<" "<<vct1[i];
                     }

                     cout<<endl;


                     cout<<vct2.size()<<endl;
                     sort(vct2.begin(),vct2.end());
                     for(int i=0;i<vct2.size() ;i++)
                     {
                         if(i==0)
                            cout<<vct2[i];
                         else
                            cout<<" "<<vct2[i];
                     }
                     cout<<endl;
                 }

                 else
                 {

                     cout<<vct2.size()<<endl;
                     sort(vct2.begin(),vct2.end());
                     for(int i=0;i<vct2.size() ;i++)
                     {
                         if(i==0)
                            cout<<vct2[i];
                         else
                            cout<<" "<<vct2[i];
                     }
                     cout<<endl;


                      cout<<vct1.size()<<endl;
                     sort(vct1.begin(),vct1.end());
                     for(int i=0;i<vct1.size() ;i++)
                     {
                         if(i==0)
                            cout<<vct1[i];
                         else
                            cout<<" "<<vct1[i];
                     }

                     cout<<endl;



                 }
                }
                else
                    cout<<-1<<endl;





    return 0;
}
