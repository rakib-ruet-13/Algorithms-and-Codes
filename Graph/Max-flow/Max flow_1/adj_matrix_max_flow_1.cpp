#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define psi pair<string,int>
#define pb push_back
#define Max 1200
#define read32(x) scanf("%d",&x)
#define read64(x) scanf("%lld",&x)
#define pi acos(-1.00000)
#define ll long long
#define rep(i,a,b) for(int i=a; i<=b; i++)

using namespace std;

int graph[Max+1][Max+1];
int visited[Max+1];
int node,edge;

int main()
{

    int tc;
    read32(tc);

    rep(cs,1,tc)
    {
        read32(node);
        read32(edge);

        rep(i,0,node)
          rep(j,0,node)
          {
              graph[i][j]=0;
          }

        rep(i,1,edge)
        {
            int u,v,cap;
            read32(u);
            read32(v);
            read32(cap);

            graph[u][v]=cap;
        }
    }




    return 0;
}
