#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 60010
#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x);
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x)  printf("%lld\n",x)
#define mem(x,val) memset(x,val, sizeof(x))

vector<int>G[Max];
vector<int>G_rev[Max];
vector<int>Componant[Max];
vector<int>graph[Max];
map<int,int>mymap;

int par[Max];
int element[Max];
int weight[Max];


int node,edge;

int visited[Max];

stack<int>stk;

int dfs(int u)
{
    visited[u]=1;

    for(int i=0 ;i<G[u].size() ; i++)
    {

        int v=G[u][i];

        if(!visited[v])
        {
            dfs(v);
        }
    }

    stk.push(u);
}

//int cnt_ele;

int dfs_add_comp(int u,int mark)
{
    visited[u]=1;
    Componant[mark].pb(u);
    //cnt_ele++;

    for(int i=0;i<G_rev[u].size() ;i++)
    {
        int v=G_rev[u][i];

        if(!visited[v])
            dfs_add_comp(v,mark);
    }

}

int c;

int dfs_new(int u)
{
    visited[u]=1;
    c+=weight[u];


    for(int i=0 ;i<graph[u].size() ; i++)
    {

        int v=graph[u][i];

        if(visited[v]!=0)
        {
            c+=weight[v];
        }

        if(!visited[v])
        {
            dfs_new(v);
        }
    }
    visited[u]=2;

   stk.push(u);
}



int dfs_new2(int u)
{
    visited[u]=1;
    //c+=weight[u];

    int p=0;

    mymap[u]=1;

   // cout<<"weight["<<u<<"]="<<weight[u]<<endl;


    for(int i=0 ;i<graph[u].size() ; i++)
    {

        int v=graph[u][i];

        if(visited[v]!=0)
        {
            if(mymap[v]==0)
               weight[u]+=weight[v];
            mymap[v]=1;
        }

        if(!visited[v])
        {
            weight[u]+=dfs_new2(v);
        }
    }
    visited[u]=2;
    //weigh[u]+=weight[v];

    return weight[u];
}




int main()
{

    int tc;
    read(tc);

    REP(cs,tc)
    {
        read(node);
        //read(edge);

        edge=node;

        REP(i,edge)
        {
            int u,v;
            read(u);
            read(v);

            G[u].pb(v);
            G_rev[v].pb(u);
        }



    mem(visited,0);


    REP(i,node)
    {
        if(!visited[i])
            dfs(i);
    }

    mem(visited,0);
    mem(element,0);

    int mark=0;

    while(!stk.empty())
    {
        int u=stk.top();
        stk.pop();

        if(!visited[u])
        {
            //cnt_ele=0;
            mark++;
            dfs_add_comp(u,mark);
            //element[mark]=cnt_ele;
        }
    }





    REP(i,node)
    {
        par[i]=i;
        weight[i]=1;
    }


    for(int i=1;i<=mark ;i++)
    {
        int mn=inf;
        for(int j=0; j<Componant[i].size(); j++)
        {
            mn=min(mn,Componant[i][j]);
            weight[Componant[i][j]]=Componant[i].size();

        }

         for(int j=0; j<Componant[i].size(); j++)
        {
           par[Componant[i][j]]=mn;
        }
    }

    for(int i=1; i<=node ;i++)
    {
        for(int j=0 ; j<G[i].size(); j++)
        {
            int v=G[i][j];

            if(par[i]!=par[v])
            {
                graph[par[i]].push_back(par[v]);

                //cout<<par[i]<<" "<<par[v]<<endl;
            }
        }
    }

      mem(visited,0);
      REP(i,node)
     {
        if(!visited[i])
            dfs_new(i);
     }

     mem(visited,0);


     int res,mx;
     res=1;
     mx=-111;

     while(!stk.empty())
     {
        // cout<<"top= "<<stk.top()<<endl;
         int p=stk.top();
         stk.pop();

         if(!visited[p])
         {
             c=0;
             mymap.clear();
             c=dfs_new2(p);

             //cout<<c<<endl;

             if(c>=mx)
             {
                 if(c==mx)
                 {
                     res=min(res,p);
                 }
                 else
                 {
                     mx=c;
                     res=p;
                 }
             }

         }
     }

     printf("Case %d: %d\n",cs,res);



    for(int i=0;i<=node;i++)
    {
        G[i].clear();
        G_rev[i].clear();
        Componant[i].clear();
        graph[i].clear();
    }

    }

    return 0;

}


