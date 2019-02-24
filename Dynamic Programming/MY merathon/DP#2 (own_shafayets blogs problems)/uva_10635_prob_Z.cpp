#include<iostream>
#include<bits/stdc++.h>
#define Max 252
using namespace std;

int dp[3][2000000];
int arr1[2000000];
int arr2[2000000];

int n1,n2,n;

int solve()
{

     for(int i=1;i<=n1;i++)
            scanf("%d",&arr1[i]);

        for(int i=1;i<=n2;i++)
           scanf("%d",&arr2[i]);

    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
    {

        if(arr1[i]==arr2[j])
        {
            dp[i%2][j]=dp[(i+1)%2][j-1]+1;
        }
        else
        {
            dp[i%2][j]=max(dp[i%2][j-1],dp[(i+1)%2][j]);
        }

    }

    }
    return dp[n1%2][n2];

}


int main()
{
    int tc;
    cin>>tc;

    int cs=0;
    while(tc--)
    {
        cs++;

        scanf("%d %d %d",&n,&n1,&n2);
        n1++;
        n2++;




        for(int i=0;i<3;i++)
            for(int j=0; j<=n2;j++)
        {
            dp[i][j]=0;
        }


        printf("Case %d: ",cs,solve());

    }
}
