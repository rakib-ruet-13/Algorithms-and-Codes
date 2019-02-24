#include<iostream>
#include<bits/stdc++.h>

#define pi acos(-1.00000)
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

int bfs_shortest_path(long long int from,long long int to);


long long int t;
 map<long long int ,int>visited;

 imap graph;
     //map<long long int ,int>level;

int main()
{
    int n;
    long long int node1,node2,from;
    int cs=0;

    while(cin>>n && n)
    {

        for(int i=0;i<n;i++)
           {
               cin>>node1>>node2;
            graph[node1].pb(node2);
            graph[node2].pb(node1);

           }
            map<long long int,vector<long long int> > ::iterator it;

           /* for(it=graph.begin();it!=graph.end();it++)
            {
                int l=it->second.size();
                cout<<it->first<<endl;
                 for(int k=0;k<l;k++)
                 {
                     cout<<it->second[k]<<"  ";
                 }
                 cout<<endl;

            }*/

            while(cin>>from>>t && (from || t))
            {
               printf("Case %d: %d nodes not reachable from node %lld with TTL = %lld.\n",++cs,bfs_shortest_path(from,from),from,t);
                visited.clear();

            }

             graph.clear();

    }


}

int bfs_shortest_path(long long int from,long long int to)
{


    visited[from]=1;
    //level[from]=0;


    queue<long long int>q;
    q.push(from);

    while(! q.empty())
    {
        long long int top=q.front();
        q.pop();

        int total=graph[top].size();

        for(int k=0;k<total;k++)
        {
            if(! visited[graph[top][k]])
            {
               visited[graph[top][k]]= visited[top]+1;
               q.push(graph[top][k]);

            }
        }


    }
    int cnt=0;
   map<long long int ,int> :: iterator it;

   for( it=visited.begin() ; it!=visited.end();it++)
   {
       if(it->second<=t+1)
        cnt++;

   }

   return graph.size()-cnt;



}

