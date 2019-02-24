#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int>graph[101];
int visited[101];
int dp[101];

int dfs(int u)
{
    if(dp[u]!=-1)
        return dp[u];



    int mx=0;

    for(int i=0;i<graph[u].size()  ;i++)
    {
        int v=graph[u][i];
        int p=dfs(v);

        if(p>mx)
        {
            mx=p;
        }

    }

    return dp[u]=1+mx;
}

int main()
{
    int n;
    while(cin>>n && n)
    {
        for(int i=1; i<=n ; i++)
        {
            int a;
            cin>>a;

            for(int k=1; k<=a;k++)
            {
                int b;
                cin>>b;
                graph[i].push_back(b);
            }
        }


            int mx=0;
            int node=1;

            memset(dp,-1,sizeof(dp));

            for(int i=1; i<=n; i++)
            {
                int lvl=dfs(i);
                //cout<<"level="<<lvl<<endl;
                if(lvl>mx)
                {
                    mx=lvl;
                    node=i;
                }
            }

            cout<<node<<endl;

            for(int i=1;i<=n;i++)
                graph[i].clear();


    }


}
