#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b ;i++)
#define pb push_back
#define read64(x) scanf("%lld",&x)
#define read32(x) scanf("%d",&x)
#define ll long long
#define mod 1e9+7
#define pi acos(-1.000)
#define Max 1010

int dp[Max][2];
int cost[Max][2];
int jump[Max][2];


using namespace std;


int cal(int tower,int floor)
{
    if(floor<0)
        return 0;

    long long r1,r2;

    if(dp[floor][tower]!=-1)
        return dp[floor][tower];

    r1=r2=100000000;

    r1=cal(tower,floor-1)+cost[floor][tower];
    r2=cal((tower+1)%2,floor-1)+cost[floor][tower]+jump[floor][tower];

    return dp[floor][tower]=min(r1,r2);
}

int main()
{

    int tc;
    read32(tc);

    rep(cs,1,tc)
    {
        int n;
        read32(n);

        rep(i,0,n-1)
        {
            read32(cost[i][0]);

        }

        rep(i,0,n-1)
        {
            read32(cost[i][1]);
        }

        rep(i,1,n-1)
        {
            read32(jump[i][1]);
        }
          rep(i,1,n-1)
        {
            read32(jump[i][0]);
        }

        rep(i,0,n)
        dp[i][0]=dp[i][1]=-1;


        long long res,r1,r2;

        r1=cal(0,n-1);
        r2=cal(1,n-1);

        res=min(r1,r2);

        printf("Case %d: %lld\n",cs,res);
    }




    return 0;
}
