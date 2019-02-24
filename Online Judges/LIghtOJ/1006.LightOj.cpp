#include<iostream>
#include<stdio.h>
using namespace std;


int main() {

    long long int dp[10007],i,n;
     int  caseno = 0, cases;


    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &dp[0], &dp[1], &dp[2], &dp[3], &dp[4], &dp[5], &n);


            for( i=6;i<=n;i++)
                {
                    dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%10000007;
                }


        printf("Case %d: %d\n", ++caseno,dp[n]%10000007);
    }
    return 0;
}
