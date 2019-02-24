#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int>vct[100100];

double dp[100100];

void divisor()
{

    for(int i=2; i<=100000; i++)
    {
        int n=i;

        for(int j=1; j*j<=n ; j++)
        {
            if(n%j==0)
            {
                 if(j*j!=n)
                 {
                     vct[i].push_back(j);
                     vct[i].push_back(n/j);
                 }
                 else
                 {
                     vct[i].push_back(j);
                 }
            }

        }
    }
}


double solve(int n)
{
    if(n==1)
        return 1;

    if(dp[n]>=0)
        return dp[n];

    double res=0;
    int p=vct[n].size();
    for(int i=1; i<vct[n].size();i++)
    {
        res+=(1.000/(double)(p-1))+(1.0000/(double)(p-1))*solve(n/vct[n][i]);
    }

    return dp[n]=res;
}


int main()
{
    divisor();

    int tc;
    scanf("%d",&tc);

    memset(dp,-1,sizeof(dp));

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n;
        scanf("%d",&n);

        if(n==1)
        {
             printf("Case %d: 0\n",cs);
        }
        else
        printf("Case %d: %.10f\n",cs,solve(n));
    }


    return 0;
}
