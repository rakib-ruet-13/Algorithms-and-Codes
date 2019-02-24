#include<iostream>
#include<bits/stdc++.h>
#define Max 10000100
using namespace std;

long long int dp[Max+4];
long long int sum[Max+4];


int main()
{

    long long int n,k;
    scanf("%lld %lld",&n,&k);


    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));

    for(int i=0;i<n;i++)
    {
        int p;
        scanf("%d",&p);

        dp[p]++;

    }

    for(int i=Max; i>=2 ; i--)
    {
        if(i%2==0)
            dp[i/2]+=dp[i]*2;
        else
        {
            dp[i/2]+=dp[i];
            dp[i/2+1]+=dp[i];
        }
    }

    //cout<<dp[1]<<endl;

    for(int i=1; i<=Max; i++)
    {
        sum[i]=sum[i-1]+dp[i];
    }


    int res=-1;

    for(int i=Max; i>=2 ;i--)
    {
        long long int have;

        if((i-1)*2>Max) //for greater parents-1;
        {
           have=sum[Max]-sum[i-1];
        }
        else
            have=sum[(i-1)*2]-sum[i-1];

        if(have>=k)
        {
            res=i;
            break;
        }

    }

    if(res==-1 && dp[1]>=k)
        res=1;


    printf("%d\n",res);

    return 0;


}
