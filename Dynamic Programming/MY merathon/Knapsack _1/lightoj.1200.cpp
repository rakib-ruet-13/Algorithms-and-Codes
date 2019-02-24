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

using namespace std;

ll n,W;

int weight[Max];
int profit[Max];

ll dp[10010][110];

long long  cal(int curr_w,int pos)
{
    if(pos>n)
        return 0;

    if(dp[curr_w][pos]!=-1)
        return dp[curr_w][pos];

    ll res1,res2;

    res1=res2=0;

    if(curr_w+weight[pos]<=W)
        res1=profit[pos]+cal(curr_w+weight[pos],pos);

    res2=cal(curr_w,pos+1);

    return dp[curr_w][pos]=max(res1,res2);
}


int main()
{

    int tc;
    read32(tc);


    rep(cs,1,tc)
    {
        read64(n);
        read64(W);

        rep(i,1,n)
        {
            int c;

            read32(profit[i]);
            read32(c);
            read32(weight[i]);

            W-=(c*weight[i]);


        }

        if(W<0)
            printf("Case %d: Impossible\n",cs);

        else
        {
            rep(i,0,W)
            rep(j,0,n)
            {
                dp[i][j]=-1;


            }


            printf("Case %d: %lld\n",cs,cal(0,1));
        }


    }




    return 0;
}
