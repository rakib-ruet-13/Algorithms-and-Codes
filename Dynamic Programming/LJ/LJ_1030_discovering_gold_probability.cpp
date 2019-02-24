#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double dp[101];
double G[101];
int N;

double solve(int pos)

{
    if(pos==N)
      return G[pos];

    if(dp[pos]>=0)
        return dp[pos];

    double res=0;

    if(N-pos<=5)
    {
        for(int j=pos+1; j<=N ; j++)
            res+=G[pos]+solve(j);

        res/=(N-pos);
    }
    else
    {
        for(int j=pos+1; j<=pos+6 ; j++)
            res+=G[pos]+solve(j);
        res/=6.00000;
    }

    return dp[pos]=res;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int cs=1;cs<=tc ; cs++)
    {
        scanf("%d",&N);

        for(int i=1 ; i<=N ; i++)
        {
            scanf("%lf",&G[i]);
        }

         for(int i=1 ; i<=N ; i++)
            dp[i]=-1;

         printf("Case %d: %.10f\n",cs,solve(1));
    }




    return 0;
}
