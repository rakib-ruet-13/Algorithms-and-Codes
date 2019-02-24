#include<iostream>
#include<bits/stdc++.h>
#define Max 101000

using namespace std;
int colour[Max];
int t;
int st_time[Max];
int ed_time[Max];

vector<int>graph[Max];

vector< pair<int ,int> >p;

bool comp( pair<int,int>a , pair<int,int>b )
{
    return a.second>b.second;
}

void dfs(int u)
{
    colour[u]=1;
    t=t+1;
    st_time[u]=t;

    for(int i=0; i<graph[u].size() ; i++)
    {

       if(colour[graph[u][i]]==0)
        {
            dfs(graph[u][i]);
        }
    }

    t=t+1;
    ed_time[u]=t;
    colour[u]=2;

}

int main()
{

    int tc;
    cin>>tc;

    for(int cs=1 ; cs<=tc ;cs++)
    {

    int n,e;
    cin>>n>>e;

      t=0;

      for(int i=0; i<e ; i++ )
      {
        int u,v;

        cin>>u;
        cin>>v;
        graph[u].push_back(v);
      }

           memset(colour,0,sizeof(colour));
           memset(ed_time,0,sizeof(ed_time));

        t=0;

    for(int i=1; i<=n ;i++)
    {
        if(colour[i]==0)
            dfs(i);
    }

    for(int i=1; i<=n ;i++)
    {
        p.push_back(pair<int,int>(i,ed_time[i]));
    }

    sort(p.begin(), p.end() , comp );

    memset(colour,0,sizeof(colour));
    memset(ed_time,0,sizeof(ed_time));

    int cnt=0;
    t=0;
    for(int i=0; i<p.size() ; i++)
    {
        if(colour[p[i].first]==0)
        {
            dfs(p[i].first);
            cnt++;
        }
    }
    cout<<cnt<<endl;


    for(int i=0; i<Max ;i++)
        graph[i].clear();
     p.clear();


    }

    return 0;
}
