#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int n;

long long dp[110][5];

long long arr[110][5];

long long solve(int row,int colour)
{
    if(row>n)
    {
        return 0;
    }


    if(dp[row][colour]!=-1)
        return dp[row][colour];

    long long res1,res2,res3,res4;

    res1=11111111;
    res2=11111111;
    res3=11111111;
    res4=11111111;


    if(colour+1<=3)
     res1=arr[row][colour]+solve(row+1,colour+1);

     if(colour+2<=3)
     res3=arr[row][colour]+solve(row+1,colour+2);

    if(colour-1>=1)
     res2=arr[row][colour]+solve(row+1,colour-1);

      if(colour-2>=1)
     res4=arr[row][colour]+solve(row+1,colour-2);



     res1=min(res1,res3);
     res2=min(res2,res4);

    return dp[row][colour]=min(res1,res2);


}



int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc; cs++)
    {

       scanf("%d",&n);

       for(int i=1;i<=n;i++)
        for(int j=1; j<=3;j++)
       {
           scanf("%lld",&arr[i][j]);
       }


       for(int i=0; i<=n; i++)
        for(int j=0; j<=3;j++)
       {
           dp[i][j]=-1;
       }

       long long res1=11111111;

       res1=min(res1,solve(1,1));
       res1=min(res1,solve(1,2));
       res1=min(res1,solve(1,3));


       printf("Case %d: %lld\n",cs,res1);

    }
    return 0;
}
