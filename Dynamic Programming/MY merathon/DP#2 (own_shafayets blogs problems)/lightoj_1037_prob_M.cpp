#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool check(int n,int pos) { return n&(1<<pos);}
int Set( int n,int pos) { return n= n | (1<<pos);}
int Reset(int n,int pos){ return n= n & ~(1<<pos);}

int n;
string grid[16];
long long int health[16];

long long int dp[1<<15];

long long int solve(int mask)
{

   // cout<<mask<<endl;

    if(mask >= ((1<<n)-1))
        return 0;

    if(dp[mask]!=-1)
      return dp[mask];

    long long int mn=11111111111;

    for(int i=0;i<n;i++)
    {
        long long int cost=0;

        if(check(mask,i)==false)
        {
            long long int res=health[i];


            long long  int min1=health[i];

              for(int j=0; j<n ; j++)
              {
                if(check(mask,j)==true)
                {
                    if(grid[j][i]!='0')
                    {
                       // cout<<"health[i]"<<health[i]<<" "<<grid[j][i]<<endl;
                        res=ceil(double(health[i])/(double)(grid[j][i]-'0'));
                       // cout<<"res"<<res<<endl;
                    }
                    min1=min(res,min1);
                }


              }

              cost=min1+solve(Set(mask,i));

               mn=min(mn,cost);

        }

    }

    return dp[mask]=mn;
}





int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        scanf("%d",&n);


        for(int i=0;i<n;i++)
            scanf("%lld",&health[i]);

        for(int i=0;i<n;i++)
        {
           cin>>grid[i];
        }

        memset(dp,-1,sizeof(dp));

        printf("Case %d: %lld\n",cs,solve(0));

        for(int i=0;i<=n;i++)
            grid[i].clear();

    }

    return 0;



}
