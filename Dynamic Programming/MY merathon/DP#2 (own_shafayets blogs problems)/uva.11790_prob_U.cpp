#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int dp1[10100];
long long int dp[10100];
long long int arr[10100];
long long int cost[10100];

int n;


long long int LIS(long long int u)
{
    if(dp[u]!=-1)
        return dp[u];

    long long int mx=0;

    for(int v=u+1; v<=n ;v++)
    {
        if(arr[u]<arr[v])
        {
            long long int p;
            p=LIS(v);

            if(p>mx)
            {
                mx=p;
            }
        }

    }
    return dp[u]=cost[u]+mx;
}






long long int LDS(long long int u)
{
    if(dp[u]!=-1)
        return dp[u];

    long long int mx=0;

    for(int v=u+1; v<=n ;v++)
    {
        if(arr[u]>arr[v])
        {
            long long int p;
            p=LDS(v);

            if(p>mx)
            {
                mx=p;
            }
        }

    }
    return dp[u]=cost[u]+mx;
}







int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ;cs<=tc ;cs++)
    {
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
            scanf("%lld",&arr[i]);

        for(int i=1;i<=n;i++)
            scanf("%lld",&cost[i]);


        long long mx1,mx2;
        mx1=mx2=0;


        arr[0]=-111111111111111;
        cost[0]=0;

        for(int i=0;i<=n;i++)
            dp[i]=-1;

        mx1=LIS(0);
        //cout<<mx1<<endl;

        arr[0]=111111111111111;
        cost[0]=0;

        for(int i=0;i<=n;i++)
            dp[i]=-1;


        mx2=LDS(0);
       // cout<<mx2<<endl;

        if(mx1>=mx2)
        printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",cs,mx1,mx2);
        else

        printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",cs,mx2,mx1);









    }
}


