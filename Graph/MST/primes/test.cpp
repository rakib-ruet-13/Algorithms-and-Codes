#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define mx 100020
vector<int> g[mx],cost[mx],Vartex,subgraph[mx],cost_sub[mx];

struct node
{
    int v;
    long long int w;
    node(int c,long long int b){v=c; w=b;}
    bool operator > ( const node& p ) const { return w > p.w;}
};

bool visited[mx];

long long int MST_primes(int src,int max_node)
{
    long long int total_cost=0,p;
    memset(visited,0,sizeof(visited));
    priority_queue <node,vector<node>, greater<node> > q;
    Vartex.push_back(src);
    for(int i=1;i<max_node;i++)
    {
            visited[src]=true;
            int u=src;
            for(int j=0;j<g[src].size();j++)
            {
                q.push(node(g[src][j],cost[src][j]));
            }

            do{
                node top = q.top();
                src = top.v;
                p = top.w;
                q.pop();
            } while(visited[src]==true && !q.empty());


            if(visited[src]==false){
                //cout<<u<< " "<<src<<endl;

            visited[u]=true;
            subgraph[u].push_back(src);
            subgraph[src].push_back(u);
            cost_sub[u].push_back(p);
            cost_sub[src].push_back(p);
             total_cost+=p;
             //cout<<total_cost<<endl;
             Vartex.push_back(src);

           }

            //Vartex.push_back(src);

           // cout<<src<<endl;

           // total_cost+=p;

    }
    return total_cost;
}

int main()
{
    Vartex.clear();
    for(int i=0;i<=mx;i++)
    {
        g[i].clear();
        cost[i].clear();
    }
    int n,e;
    int u,v,w;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);

    }
    printf("%lld\n",MST_primes(1,n));
    return 0;
}
