#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double dp[505][505];

double solve(long long r,long long b)
{
    if(r==0)
        return 1;
    if(b<=0)
        return 0;

    if(dp[r][b]>=0)
        return dp[r][b];

    double res1,res2;
    res1=res2=0;

    res1=((double)r/(double)(r+b))*solve(r-1,b-1);
    res2=((double)b/(double(r+b)))*(solve(r,b-2));

    return dp[r][b]=res1+res2;



}
int main()
{
    int tc;
    scanf("%d",&tc);

    memset(dp,-1,sizeof(dp));

    for(int cs=1 ; cs<=tc ;cs++)
    {
        int R,B;
        scanf("%d %d",&R,&B);

        printf("Case %d: %.10f\n",cs,solve(R,B));


    }

    return 0;
}
