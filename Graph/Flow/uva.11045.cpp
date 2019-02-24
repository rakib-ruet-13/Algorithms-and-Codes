#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x)
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)
#define mem(x,val) memset(x,val,sizeof(x))
#define Max 105

vector<int>graph[Max];
int cap[Max][Max];
int visited[Max];
int par[Max];

int node,edge;
int total;

bool bfs(int src,int sink)
{
    mem(visited,0);
    mem(par,-1);

    visited[src]=1;
    queue<int>q;

    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        if(u==sink)
            return true;

        for(int i=0; i< graph[u].size()  ; i++ )
        {
            int v=graph[u][i];

            if(visited[v]==0 && cap[u][v]>0)
            {
                visited[v]=1;
                par[v]=u;
                q.push(v);
            }
        }
    }

    return false;
}


int Ford_Fulkerson(int src,int sink)
{
    int max_flow=0;

    while(bfs(src,sink))
    {

        int mn=inf;

        for(int v=sink ; v!=src ; v=par[v])
        {
            int u=par[v];
            mn=min(mn,cap[u][v]);
        }

        for(int v=sink ; v!=src ; v=par[v])
        {
            int u=par[v];
            cap[u][v]-=mn;
            cap[v][u]+=mn;
        }

        max_flow+=mn;

    }
    return max_flow;

}


int check_pos(string str)
{
   int val;

   if(str=="XXL")
   {
       val=31;
   }
   if(str=="XL")
   {
       val=32;
   }

   if(str=="L")
   {
       val=33;
   }

   if(str=="M")
   {
       val=34;
   }
   if(str=="S")
   {
       val=35;
   }
   if(str=="XS")
   {
       val=36;
   }

   return val;


}

void Input()
{


    for(int i=0;i<=37; i++)
        for(int j=0;j<=37;j++)
    {
        cap[i][j]=0;
    }

    for(int i=0;i<= 37; i++)
        graph[i].clear();


    REP(i,node)
    {
        string str1,str2;

        cin>>str1>>str2;

        int u=check_pos(str1);
        int v=check_pos(str2);

        //cout<<i<<" ** "<<u<<" ** "<<v<<endl;

        graph[i].push_back(u);
        graph[u].push_back(i);

        cap[i][u]=1;

         graph[i].push_back(v);
         graph[v].push_back(i);

         cap[i][v]=1;

         graph[0].push_back(i);
         cap[0][i]=1;


    }

    for(int i=31; i<=36; i++)
    {
        graph[i].pb(37);
        graph[37].pb(i);

        cap[i][37]=total/6;
    }

}




int main()
{
    int tc;
    read(tc);
    REP(cs,tc)
    {

        int src,sink;

        read(total);
        read(node);

        Input();

        src=0;
        sink=37;

        int res=Ford_Fulkerson(src,sink);

        if(res==node)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;


    }

}

