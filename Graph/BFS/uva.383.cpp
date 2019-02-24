#include<iostream>
#include<bits/stdc++.h>

#define pi acos(-1.000)
#define rep(a,x) for(int i=a;i<=x;i++)
#define pb(x) push_back(x)

#define ll long long

#define read32(x) scanf("%d",&x)
#define read64(x) scanf("%lld",%x)
#define read_s(x) scanf("%s",&x)

#define write32(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)

#define uu first
#define vv second

#define pii pair<int,int>
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define valid(x,y) if(x>=1 && x<=row && y>=1 &&& y<=row)

#define imap map<ll,vector<ll> >
#define smap map<string,vector<string> >

using namespace std;

ll power(ll base,ll p);
ll mod(ll a,ll b);
int row,col;

smap graph;

map<string,int>visited;
map<string,int>level;
map<string,string>par;


 int bfs(string src,string des )
 {
     visited.clear();
     level.clear();
     par.clear();

     queue<string>q;
     visited[src]=1;
     level[src]=0;
     q.push(src);

     while(! q.empty())
     {
         string top=q.front();
         q.pop();


         int total=graph[top].size();

         for(int i=0;i<total;i++)
         {
             string u=graph[top][i];
             if(visited[u]==0)
             {
                 visited[u]=1;
                 level[u]=level[top]+1;
                 par[u]=top;
                 q.push(u);
             }
         }


     }

       return level[des];

 }


int main()
{
    int tc,node,edge,query;
    read32(tc);
    int cs=1;
    printf("SHIPPING ROUTES OUTPUT\n");
    while(tc--)
    {
        read32(node);
        read32(edge);
        read32(query);

        rep(1,node)
        {
            string str;
            cin>>str;

        }

        string str1,str2;

        rep(1,edge)
        {
            cin>>str1>>str2;
            graph[str1].pb(str2);
            graph[str2].pb(str1);
        }

        printf("\nDATA SET  %d\n\n",cs++);

        rep(1,query)
        {
            ll cost;
            cin>>cost;
            getchar();

            cin>>str1>>str2;
            ll ans=bfs(str1,str2)*cost*100;



            if(ans==0)
                printf("NO SHIPMENT POSSIBLE\n");
            else
                printf("$%lld\n",ans);

        }

        graph.clear();



    }
    cout<<"\nEND OF OUTPUT\n";




    return 0;
}









ll power(ll base,ll p)
{
    if(p==0)
        return 1;
    ll ans=1;
      rep(1,p)
        ans=ans*base;
    return ans;
}
ll mod(ll a,ll b)
{
    if(a==0)
        return b;
    else
        return mod(b,a%b);
}
