#include<iostream>
#include<bits/stdc++.h>

#define pi acos(-1.0000);
#define rep(x,n) for(int i=x;i<=n;i++)
#define LL long long
#define pb(x) push_back(x)
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define pii pair<int,int>

#define smap map<string,vector<string> >
#define imap map<long long int,vector<long long int> >

using namespace std;

void bfs_map(string from,string to);

map<string,int>visited;
map<string,int>level;
map<string,string>par;
smap graph;



int main()
{
    bool check=false;


    int n;

    string str1,str2;

    while(cin>>n)
    {

        getchar();
        for(int i=0;i<n;i++)
        {
           cin>>str1>>str2;
           graph[str1].pb(str2);
           graph[str2].pb(str1);
        }

        cin>>str1>>str2;
        if(check)
        {
            cout<<endl;
        }
        else
            check=true;

        bfs_map(str2,str1);
        graph.clear();





    }
return 0;

}

void bfs_map(string from,string to)
{
   queue<string>q;
   visited[from]=1;
   level[from]=0;

   q.push(from);

   while(!q.empty())
   {
       string top=q.front();
       q.pop();
       int total=graph[top].size();

       for(int i=0;i<total;i++)
       {
           string u=graph[top][i];
           if(visited[u]==0)
           {
               visited[u]=1;
               par[u]=top;
               level[u]=level[top]+1;
               q.push(u);
           }
       }
   }

   if(level[to]!=0)
   {
       string str=to;

       while(level[str]!=0)
       {
           cout<<str<<" "<<par[str]<<endl;
           str=par[str];

       }


   }
   else
    cout<<"No route"<<endl;

   visited.clear();
   level.clear();
   par.clear();

}
