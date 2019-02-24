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

int height[110];
int dp[110][110][110];
int n;

using namespace std;

int cal(int i,int left,int right)
{
    if(i>n)
        return 0;

    if(dp[i][left][right]!=-1)
        return dp[i][left][right];

    int res1,res2,res3;

    res1=res2=res3=0;


    //cout<<"left="<<left <<" right= "<<right<<endl;


    if(height[i]>=height[left] && height[i]<=height[right])
        res1=1+cal(i+1,i,right);

    if(height[i]<=height[right] && height[i]>=height[left])
        res2=1+cal(i+1,left,i);

    res3=cal(i+1,left,right);




    res2=max(res1,res2);

    return dp[i][left][right]=max(res2,res3);
}


int main()
{
    int tc;
    read32(tc);


    rep(cs,1,tc)
    {
        read32(n);

        int mx=0;


        height[0]=0;
        rep(i,1,n)
        {
            read32(height[i]);
            mx=max(mx,height[i]);
        }

        height[n+1]=100000000;

        rep(i,0,n+1)
        rep(j,0,n+1)
        rep(k,0,n+1)
        {
            dp[i][j][k]=-1;
        }

        printf("Case %d: %d\n",cs,cal(1,0,n+1));

    }



    return 0;
}
