#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long dp[1<<17][21];

int Set(int n,int pos) { return n | 1<<pos ;}
bool check(int n,int pos) { return n & 1<<pos;}

int digit;
int mod;
int base;
string str;

long long solve(int mask,int k)
{
    if(mask>=((1<<digit)-1))
    {
        if((k+mod)%mod==0)
            return 1;
        else
            return 0;
    }

    if(dp[mask][k]!=-1)
        return dp[mask][k];

    long long res=0;

    for(int i=0; i<digit ; i++)
    {
        if(!check(mask,i))
        {
            if(str[i]<='9')
            {
             res+=solve(Set(mask,i), ((str[i]-'0')+ (k*base))%mod);
            }
            else
            {
                 res+=solve(Set(mask,i), ((str[i]-'A'+10)+ (k*base))%mod);
            }
        }
    }
    return dp[mask][k]=res;
}

int main()
{
    int tc;

    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {


        scanf("%d %d",&base,&mod);
        cin>>str;
        digit=str.size();

        for(int i=0; i<= (1<<digit) ; i++)
            for(int j=0; j<=mod ; j++)
        {
            dp[i][j]=-1;
        }
        long long res=solve(0,0);

        printf("Case %d: %lld\n",cs,res);


    }

    return 0;



}
