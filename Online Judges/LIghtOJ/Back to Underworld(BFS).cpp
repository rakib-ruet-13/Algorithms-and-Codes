#include<iostream>
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define Max 20010

using namespace std;

vector<int>graph[Max+1];
int visited[Max+1];
int colour[Max+1];

int colour_bfs(int src)
{
    int cnt0=0;
    int cnt1=0;


    queue<int>q;

    q.push(src);
    colour[src]=0;
     cnt0++;
    visited[src]=1;


    while(!q.empty())
    {
        int top=q.front() ; q.pop();

        for(int i=0; i<graph[top].size();i++)
        {
            int u=graph[top][i];

            if(visited[u]==0)
            {
                visited[u]=1;
                if(colour[top]==1)
                {
                    colour[u]=0;
                    cnt0++;
                }
                else
                {
                        colour[u]=1;
                        cnt1++;
                }
                q.push(u);
            }
        }


    }

    return(max(cnt0,cnt1));
}

int main()
{

     //freopen("input.txt","r",stdin);
    int tc;

    scanf("%d",&tc);

    for(int cs=1 ;cs<=tc ;cs++)
    {
        mem(visited,0);
        mem(colour,0);


        int n,n1,n2,mx=-1111;
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&n1,&n2);

            graph[n1].pb(n2);
            graph[n2].pb(n1);
            n1=max(n1,n2);
            mx=max(n1,mx);
        }

        int ans=0;

        for(int i=1 ;i<=mx;i++)
        {
            if(visited[i]==0 && graph[i].size()>0)
            {
                ans+=colour_bfs(i);
            }
        }
         for(int i=0; i<=mx;i++)
            graph[i].clear();

        printf("Case %d: %d\n",cs,ans);
    }


}

