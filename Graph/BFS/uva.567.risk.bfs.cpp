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

int bfs(int src,int tar);

using namespace std;

vector<int>vct[21];
int visited[21];
int level[21];

int main()
{
    int n,tar,src,cs=0;
    int node;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>node;
            vct[1].push_back(node);
            vct[node].push_back(1);
        }

        for(int i=2;i<=19;i++)
        {
            cin>>n;
            for(int j=1;j<=n;j++)
            {
                cin>>node;
                vct[i].pb(node);
                vct[node].pb(i);
            }
        }

        cin>>n;
        printf("Test Set #%d\n",++cs);

        for(int i=1;i<=n;i++)
        {
            cin>>src>>tar;
            printf("%2d to %2d: %d\n",src,tar,bfs(src,tar));


        }
        cout<<endl;
        for(int i=0;i<21;i++)
            vct[i].clear();
    }
}
int bfs(int src,int tar)
{
    queue<int>q;

    mem(visited,0);
    mem(level,0);

    visited[src]=1;
    level[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        for(int i=0;i<vct[top].size();i++)
        {
            int x=vct[top][i];
            if(visited[x]==0)
            {
                visited[x]=1;
                level[x]=level[top]+1;
                q.push(x);
            }
        }
    }
    return level[tar];

}
