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

long long int power(long long int base,long long int p)
{
    if(p==0)
        return 1;

    LL ans=1;
    for(int i=1;i<=p;i++)
        ans=ans*base;
    return ans;

}

long long int gcd(long long int a, long long int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}




int main()
{

    //cout<<gcd(30,0);
    return 0;
}










int bfs_shortest_path(long long int from,long long int to)
{


    visited[from]=1;


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
