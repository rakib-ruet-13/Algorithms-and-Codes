#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int Set(int n,int pos) { return n | 1<<pos ;}
bool check(int n,int pos) { return n & 1<<pos;}


long long dp[34][2][2][35];
int N;

long long solve(int pos, int pre,int bound,int cnt)
{
    if(pos<0)
        return cnt;

    if(dp[pos][pre][bound][cnt]!=-1)
        return dp[pos][pre][bound][cnt];

    long long res=0;

    if(pre==1)
    {
        if(bound==1)
        {
           if(check(N,pos))
               res=solve(pos-1,1,1,cnt+1)+solve(pos-1,0,0,cnt);
           else
               res=solve(pos-1,0,1,cnt);

        }
        else
        {
            res=solve(pos-1,1,0,cnt+1)+solve(pos-1,0,0,cnt);

        }

    }
    else
    {
        if(bound==1)
        {
            if(check(N,pos))
                res=solve(pos-1,1,1,cnt)+solve(pos-1,0,0,cnt);
            else
                res=solve(pos-1,0,1,cnt);

        }
        else
        {
            res=solve(pos-1,1,0,cnt)+solve(pos-1,0,0,cnt);
        }


    }

    return dp[pos][pre][bound][cnt]=res;




}


int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        scanf("%lld",&N);

        memset(dp,-1,sizeof(dp));

        int ind;

        for(ind=31; ind>=0 ;ind--)
            if(check(N,ind))break;

        long long res=0;
        res=solve(ind,0,1,0);

        printf("Case %d: %lld\n",cs,res);
    }




    return 0;
}
