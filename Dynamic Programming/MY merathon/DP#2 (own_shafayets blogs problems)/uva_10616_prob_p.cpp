#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long dp[210][22][12];
long long arr[210];

int D,M,n;

long long solve(int pos, int sum,int take)
{
    if(pos>n || take==M)
    {
        if(take==M)
        {
            if(sum%D==0)
                return 1;
            else
                return 0;
        }
        else
         return 0;
    }


    if(dp[pos][sum][take]!=-1)
        return dp[pos][sum][take];

    long long res1=0;
    long long res2=0;
    res1=solve(pos+1, (((sum+arr[pos])%D)+D)%D ,take+1);

    res2=solve(pos+1, sum,take);

    return dp[pos][sum][take]=res1+res2;




}


int main()
{
    int q;
    int cs=0;
    while(cin>>n>>q)
    {
        if(n==0 && q==0)
            break;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }

        printf("SET %d:\n",++cs);

        for(int m=1;m<=q;m++)
        {
            cin>>D;
            cin>>M;

            for(int i=0;i<=n;i++)
                for(int j=0; j<=D;j++)
                  for(int k=0;k<=M;k++)
                  dp[i][j][k]=-1;

            long long res=solve(1,0,0);

            printf("QUERY %d: %lld\n",m,res);


        }



    }




    return 0;
}
