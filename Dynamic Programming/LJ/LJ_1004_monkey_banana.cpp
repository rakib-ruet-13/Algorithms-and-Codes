#include<bits/stdc++.h>
using namespace std;


int n;
long long arr[202][101];
long long dp[202][101];

long long solve(int i,int j)
{
    //cout<<"i j="<<" "<<i<<" "<<j<<endl;
    if(j>n || j<1)
        return 0;

    if(i> 2*n-1)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    long long res1,res2;
    res1=res2=0;

    if(i<n)
    {
        res1=arr[i][j]+solve(i+1,j);
        res2=arr[i][j]+solve(i+1,j+1);
    }
    else
    {
        res1=arr[i][j]+solve(i+1,j-1);
        res2=arr[i][j]+solve(i+1,j);
    }

   // cout<<i<<" * "<<j<<" * "<<max(res1,res2)<<endl;

    return dp[i][j]=max(res1,res2);

}


int main()
{
    int tc;
    scanf("%d",&tc);


    for(int cs=1 ; cs<=tc ;cs++)
    {
        scanf("%d",&n);

        for(int i=0 ;i<=2*n-1; i++)
            for(int j=0; j<=n ; j++)
        {
            arr[i][j]=0;
            dp[i][j]=-1;
        }

        for(int i=1; i<=n ; i++)
            for(int j=1; j<=i; j++)
        {
            scanf("%lld",&arr[i][j]);
        }

        for(int i=n+1; i<=2*n-1 ; i++)
            for(int j=1; j<=2*n-i; j++)
        {
            scanf("%lld",&arr[i][j]);
        }



        printf("Case %d: %lld\n",cs,solve(1,1));


         for(int i=1; i<=2*n-1 ; i++)
            for(int j=1; j<=n; j++)
            {
                dp[i][j]=-1;
                arr[i][j]=0;
            }



    }
}
