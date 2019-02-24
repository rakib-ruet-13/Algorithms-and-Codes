#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int row;
int n;
long long dp[210][210];
long long arr[210][210];


long long solve(int i,int j)
{

    if( i>row || j<1 || j>i)
        return 0;

    if(arr[i][j]==-1)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    long long res1,res2,res3;
    res1=res2=0;

    res1=arr[i][j]+solve(i+1,j);

    if(i<n)
     res2=arr[i][j]+solve(i+1,j+1);
    else
     res2=arr[i][j]+solve(i+1,j-1);



    res1=max(res1,res2);

    return dp[i][j]=res1;
}


int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {

        scanf("%d",&n);

        row=2*n-1;

        for(int i=0 ;i<=202;i++)
            for(int j=0; j<=202; j++)
        {
            dp[i][j]=-1;
            arr[i][j]=-1;
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
        {
            scanf("%lld",&arr[i][j]);
        }

        for(int i=n+1; i<=row;i++)
            for(int j=1;j<=row-i+1 ;j++)
        {
            scanf("%lld",&arr[i][j]);
        }



          /* for(int i=1; i<=row;i++)
           {
            for(int j=1;j<=4 ;j++)
            {
               printf("%d ",arr[i][j]);
            }

            printf("\n");
           }*/



        long long res=solve(1,1);

        printf("Case %d: %lld\n",cs,res);
    }


    return 0;


}
