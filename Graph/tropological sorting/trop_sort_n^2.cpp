#include<iostream>
#include<bits/stdc++.h>
#define read32(x) scanf("%d",&x)
#define read64(x) scanf("%lld",&x)

#define rep(i,a,b) for(int i=a ;i<=b ;i++)
#define pi acos(-1.00)




using namespace std;

int graph[1201][1201];
int ind[1201];



void clr(int n)
{
    rep(i,0,n)
    rep(j,0,n)
      graph[i][j]=0;
}



int main()
{

    int tc;
    read32(tc);

    rep(cs,1,tc)
    {
        int n;
        read32(n);
        int edge;
        read32(edge);


        clr(n);


        rep(i,1,edge)
        {
            int u,v;
            read32(u);
            read32(v);

            graph[u][v]++;
            ind[v]++;

        }


        queue<int>q;

        for(int i=1; i<=n ;i++)
        {
            if( ind[i]==0)
            q.push(i);

        }

        vector<int>res;

        while(!q.empty())
        {
            int t=q.front();

            res.push_back(t);

            q.pop();


            rep(i,1,n)
            {
                if(graph[t][i]!=0)
                {
                    graph[t][i]==0;
                    ind[i]--;

                    if(ind[i]==0)
                        q.push(i);

                }
            }
        }


        printf("Case %d:\n",cs);

        for(int i=0; i<res.size() ; i++)
        {
            printf("%d ",res[i]);
        }
        printf("\n");

        res.clear();

      }



}
