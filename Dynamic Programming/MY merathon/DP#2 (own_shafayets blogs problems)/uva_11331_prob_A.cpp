#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 2010

int colour[Max];
vector<int>graph[Max];
vector<int>vct;

int b,c;

int n;

int cnt;

bool bipertite(int src)
{
    colour[src]=1;
    queue<int>q;

    q.push(src);
    cnt++;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();


         for(int i=0;i<graph[u].size();i++)
         {
             int v=graph[u][i];

             if(colour[v]==-1)
             {
                 cnt++;
                 colour[v]=1-colour[u];
                 q.push(v);

             }

             if(colour[u]==colour[v])
                return false;
         }

    }
    //cout<<cnt<<endl;
    return true;



}


int dp[2010][2010];

int knapsack(int i,int val)
{

    //cout<<i<<" "<<val<<endl;

    if(i>=n)
    {
        if(val==c)
        {
            //cout<<val<<endl;
            return 1;
        }
        else
            return 0;
    }
   // cout<<i<<" "<<val<<endl;

    if(val>c)
    return 0;


   // cout<<dp[i][val]<<endl;
      if(dp[i][val]!=-1)
        return dp[i][val];

     int res1=knapsack(i+1,val+vct[i]/2);
     int res2=knapsack(i+1,val+(vct[i]-vct[i]/2));

     return dp[i][val]=(res1||res2);


}

int main()
{

    int tc;

    scanf("%d",&tc);

    while(tc--)
    {
        int a;
        vct.clear();

        for(int i=0;i<Max;i++)
            graph[i].clear();

        memset(colour,-1,sizeof(colour));




        scanf("%d %d %d",&b,&c,&a);

        for(int i=0;i<a;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);

            graph[u].push_back(v);
            graph[v].push_back(u);
        }


        bool flag=true;

        for(int i=1;i<=b+c;i++)
        {
            if(colour[i]==-1)
            {
                cnt=0;
                if(bipertite(i))
                {
                   // cout<<"in"<<endl;
                    vct.push_back(cnt);
                  // cout<<cnt<<endl;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
        }

        if(flag)
        {



            n=vct.size();

            //cout<<"n="<<n<<endl;

           // cout<<dp[0][0]<<endl;


           for(int i=0;i<=n;i++)
            for(int j=0;j<=b+c;j++)
            {
                dp[i][j]=-1;
            }



           // cout<<"knapsack"<<endl;



            if(knapsack(0,0))
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }



    return 0;
}
