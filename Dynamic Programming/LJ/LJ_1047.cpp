#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int check(int N,int pos){ return N&(1<<pos);}
int Set(int N,int pos){ return N=(N|(1<<pos));}
int Reset(int N,int pos){ return N=(N & ~(1<<pos));}


int color[22][4];

int dp[22][4];

int n;





int solve(int row,int col)
{
    if(row>n)
        return 0;

    if(dp[row][col]!=-1)
        return dp[row][col];

    int mn=100000000;

    if(col==0)
    {
        mn=min(mn,color[row][1]+solve(row+1,1));
         mn=min(mn,color[row][2]+solve(row+1,2));
          mn=min(mn,color[row][3]+solve(row+1,3));
    }
    if(col==1)
    {
         mn=min(mn,color[row][2]+solve(row+1,2));
          mn=min(mn,color[row][3]+solve(row+1,3));

    }
    if(col==2)
    {
         mn=min(mn,color[row][1]+solve(row+1,1));
          mn=min(mn,color[row][3]+solve(row+1,3));

    }
    if(col==3)
    {
         mn=min(mn,color[row][1]+solve(row+1,1));
          mn=min(mn,color[row][2]+solve(row+1,2));

    }

    return dp[row][col]=mn;



}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        scanf("%d",&n);

        for(int i=1; i<=n;i++)
            for(int j=1; j<=3; j++)
            scanf("%d",&color[i][j]);



          memset(dp,-1,sizeof(dp));


        printf("Case %d: %d\n",cs,solve(1,0));


    }





    return 0;
}

