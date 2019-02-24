#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int check(int N,int pos){ return N&(1<<pos);}
int Set(int N,int pos){ return N=(N|(1<<pos));}
int Reset(int N,int pos){ return N=(N & ~(1<<pos));}

int arr[17][17];
int dp[17][1<<17];
int n;


long long solve(int pos,int mask)
{


    if(mask== ((1<<n) -1))
        return 0;

    if(pos>n)
        return 0;

    if(dp[pos][mask]!=-1)
        return dp[pos][mask];

    long long mx=0;



    for(int i=0; i<n; i++)
    {
        long long res=0;

        if( !check(mask,i))
        {
            res=arr[pos][i+1]+solve(pos+1,Set(mask,i));

        }
        mx=max(mx,res);

    }

    return dp[pos][mask]=mx;

}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        scanf("%d",&n);


        for(int i=1; i<=n ;i++)
            for(int j=1; j<=n ; j++)
        {
            scanf("%d",&arr[i][j]);
        }

        for(int i=0; i<=n ;i++)
            for(int j=0; j<= ((1<<n)-1) ; j++)
        {
            dp[i][j]=-1;
        }

        printf("Case %d: %lld\n",cs,solve(1,0));


    }





    return 0;
}
