#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int n;
vector<int>graph[110];

pair<int,int>dp[110];


pair<int,int> longest(int u)
{
    if(dp[u].first!=-1)
    {
         return dp[u];
    }


    pair<int,int> mx;
    mx.first=0;
    mx.second=1111111;

    for(int i=0 ;i< graph[u].size() ;i++)
    {
        int v=graph[u][i];
        pair<int,int> p=longest(v);


        if(mx.first<p.first)
        {
            mx=p;
        }
        else if(mx.first==p.first)
        {
            if(mx.second>p.second)
                mx=p;
        }

    }

    if(graph[u].size()==0)
        dp[u].second=u;
    else
        dp[u].second=mx.second;

     dp[u].first=1+mx.first;

     return dp[u];

}





int main()
{

    int cs=0;
    while(cin>>n && n)
    {
        int src;
        cin>>src;
        cs++;
        int a,b;

        while(cin>>a>>b)
        {
            if(!(a||b))
                break;

            graph[a].push_back(b);
        }
        for(int i=1;i<=100;i++)
            dp[i].first=-1;


        pair<int,int>res=longest(src);


        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",cs,src,res.first-1,res.second);


        for(int i=0;i<=100;i++)
            graph[i].clear();
    }

    return 0;
}
