#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int arr;
vector<long long>vct;
string str;

map<int,int>dp[4];

int coin[]={1234567,123456,1234};

int solve(int i,int rem)
{

   if(dp[i][rem]!=0)
        return dp[i][rem];

    if(rem==0)
        return 1;

    if(rem<0)
        return 2;

    if(i>=3)
    {
        if(rem==0)
            return 1;
        else
            return 2;
    }



        int res1,res2;

    if(coin[i]<=rem)
       res1=solve(i,rem-coin[i]);

       if(res1==1)
        return dp[i][rem]=1;

       res2=solve(i+1,rem);


    if(res1==1 || res2==1)
        return dp[i][rem]=1;
    else
        return dp[i][rem]=2;


}


int main()
{
    long long int n;
    cin>>n;


    if(solve(0,n)==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}

