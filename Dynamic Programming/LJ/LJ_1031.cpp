#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[101][101][2];

int arr[101];
int N;

int solve(int i,int j,int dir)
{

    if(i==j)
      return arr[i];


    if(i>j)
        return 0;



    if(dp[i][j][dir]!=-11111111)
        return dp[i][j][dir];




        int res1,res2;
        res1=res2=-19999999;

        if(dir==0)
        {
           res1=arr[i]+solve(i+1,j,0);
           res2=arr[i]- max(solve(i+1,j,0),solve(i+1,j,1));

        }
        else
        {
           res1=arr[j]+solve(i,j-1,1);
           res2=arr[j]- max(solve(i,j-1,0),solve(i,j-1,1));
        }

       // cout<<"res1 res2 = "<<res1<<  "  "<<res2<<"   i j dir "<<i<<"  "<<j<<"  "<<dir<<endl;

        return dp[i][j][dir]=max(res1,res2);



}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ;cs++)
    {
        scanf("%d",&N);



        int sum=0;

        for(int i=1; i<=N ;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }



        for(int i=0; i<=N ; i++)
            for(int j=0; j<=N ; j++)
            {
               dp[i][j][0]=dp[i][j][1]=-11111111;

            }



        int res1=solve(1,N,0);

         for(int i=0; i<=N ; i++)
            for(int j=0; j<=N ; j++)
               dp[i][j][0]=dp[i][j][1]=-11111111;


         res1=max(res1,solve(1,N,1));


         //int res2=sum-res1;


         printf("Case %d: %d\n",cs,res1);

    }


}
