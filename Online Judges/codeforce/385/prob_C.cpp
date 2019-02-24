#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define Max 210000

bool visited[Max];

int cnt;

int cnt5;

vector<int>G[Max];

void dfs(int u)
{
    visited[u]=1;

    cnt++;


    for(int i=0 ; i<G[u].size(); i++)
    {
        int v=G[u][i];

        if(!visited[v])
            dfs(v);
    }
}




void dfs2(int u)
{
    visited[u]=1;

    cnt+=G[u].size();

    //cout<<u<<" "<<cnt<<endl;

    for(int i=0 ; i<G[u].size(); i++)
    {
        int v=G[u][i];

        if(!visited[v])
            dfs2(v);
    }
}





void dfs3(int u)
{
    visited[u]=1;

    cnt+=G[u].size();
     cnt5+=1;
    //cout<<u<<" "<<cnt<<endl;

    for(int i=0 ; i<G[u].size(); i++)
    {
        int v=G[u][i];

        if(!visited[v])
            dfs3(v);
    }
}


int main()
{

    int n,m,k;

    scanf("%d %d %d",&n,&m,&k);

    vector<int>vct;

    for(int i=1;i<=k ;i++)
    {
        int temp;
        scanf("%d",&temp);

        vct.push_back(temp);
    }


    for(int i=1; i<=m ;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);

        G[u].push_back(v);
        G[v].push_back(u);
    }



    int mx=1;
    memset(visited,0,sizeof(visited));

    vector<int>res;

    for(int i=0; i<k ;i++)
    {
        cnt=0;
        dfs(vct[i]);


        if(cnt>mx)
        {
            res.clear();
            res.push_back(vct[i]);
            mx=cnt;
        }
        else if(cnt==mx)
        {
            res.push_back(vct[i]);
        }

    }


    int iso;

    iso=0;


    // memset(visited,0,sizeof(visited));


    int ext=0;

    for(int i=1; i<=n ;i++)
    {
        if(visited[i]==0)
            {
                cnt=0;
                cnt5=0;
                dfs3(i);
                iso+=cnt5;
                ext+=cnt;
            }
    }

    //cout<<iso<<" "<<mx<<" "<<mn<<endl;

    memset(visited,0,sizeof(visited));


    int mn=11111111;
    for(int i=0; i<res.size() ; i++)
    {
      cnt=0;
     // cout<<"res==="<<res[i]<<" ";
      dfs2(res[i]);
      //cout<<cnt<<endl;

      mn=min(cnt,mn);
    }

    //cout<<iso<<" "<<mx<<" "<<mn<<" "<<ext<<endl;


    long long l=mx+iso;

    long long int ans=(l*(l-1)-mn-ext)/2;


    cout<<ans<<endl;






}
