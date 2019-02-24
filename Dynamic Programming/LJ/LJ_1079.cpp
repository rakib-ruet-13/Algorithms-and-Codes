#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double P;
int N;
int dp[101][10011];
int doller[101];
double prob[101];

int solve(int pos,int take,double sum)
{
    if(sum-P > 0.000000000)
        return take;
    if(pos>N)
        return take;

    if(dp[pos][take]!=-1)
        return dp[pos][take];

    double temp;
    temp=sum+ ((double)1.000000000-sum)*prob[pos];

    int res1,res2;
    res1=res2=0;

    if(temp-P<=0.000000000)
    {
        res1=solve(pos+1,take+doller[pos],temp);
        res2=solve(pos+1,take,sum);
    }
    else
    {
        res1=solve(pos+1,take,sum);
    }

    return dp[pos][take]=max(res1,res2);

}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        scanf("%lf %d",&P,&N);

        for(int i=1; i<=N ; i++)
        {
            scanf("%d %lf",&doller[i],&prob[i]);

        }

        memset(dp,-1,sizeof(dp));


        printf("Case %d: %d\n",cs,solve(1,0,0.000000000000));



    }
    return 0;

}
