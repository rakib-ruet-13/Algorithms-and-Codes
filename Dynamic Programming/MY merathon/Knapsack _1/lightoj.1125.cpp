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

long long int dp[210][22][12];
int num[210];
int n,m,d;

long long int cal(int i,int j,int k)
{
        if(k==m)
        {
          if(j%d==0)
            return 1;
          else
            return 0;
        }

       if(i>n)
        return 0;

    if(dp[i][j][k]!=-1)
        return dp[i][j][k];

    long long int res1,res2;

     res1=res2=0;

     res1=cal(i+1,(((j+num[i])%d)+d)%d,k+1);
     res2=cal(i+1,((j%d)+d)%d,k);

     //cout<<res1<<res2<<endl;

    return dp[i][j][k]=res1+res2;


}

int main()
{
    int tc;
    read32(tc);

    rep(cs,1,tc)
    {
        int q;

        read32(n);
        read32(q);

        rep(i,1,n)
        read32(num[i]);



       printf("Case %d:\n",cs);

       rep(i,1,q)
       {
           rep(i,0,n)
            rep(j,0,22)
             rep(k,0,12)
            {
              dp[i][j][k]=-1;
            }

           read32(d);
           read32(m);

           printf("%lld\n",cal(1,0,0));
       }





    }

    return 0;
}
