#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[110][110];
int arr1[110];
int arr2[110];
int n1,n2;

int solve(int i,int j)
{
    if(dp[i][j]!=-1)
      return dp[i][j];

    if(i>n1 || j>n2)
        return 0;

    int res1,res2,res3;

    res1=res2=res3=0;

    if(arr1[i]==arr2[j])
        res1=1+solve(i+1,j+1);

        res2=solve(i,j+1);
        res3=solve(i+1,j);


    res1=max(res1,res2);
    res1=max(res1,res3);

    return dp[i][j]=res1;


}

int main()
{

    int cs=0;

    while(cin>>n1>>n2)
    {
        cs++;

        for(int i=0; i<=110;i++)
            for(int j=0;j<=110;j++)
               dp[i][j]=-1;



        if(n1==0 && n2==0)
            break;

        for(int i=1;i<=n1; i++)
        {
            cin>>arr1[i];
        }

        for(int i=1; i<=n2 ;i++)
        {
            cin>>arr2[i];
        }



        printf("Twin Towers #%d\n",cs);
        printf("Number of Tiles : %d\n\n",solve(1,1));
    }

    return 0;
}
