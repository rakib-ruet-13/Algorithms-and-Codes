#include<iostream>
#include<bits/stdc++.h>


using namespace std;


long long dp[23][11111];
vector<int>vct;
int n;

long long int call(int pos,int val)
{
    if(pos==n)
    {
        if(val==0)
            return 1;
        else
            return 0;
    }


    if(val<0)
        return 0;

    if(dp[pos][val]!=-1)
    {
        return dp[pos][val];
    }

    long long int res1=0;
    long long int res2=0;

    if(val>=vct[pos])
      res1=call(pos,val-vct[pos]);

    res2=call(pos+1,val);


    return dp[pos][val]=res1+res2;
}


int main()
{

    for(int i=1; i<=21 ;i++)
    {
        vct.push_back(i*i*i);
    }

    n=vct.size();
    int make;
    while(cin>>make)
    {
        for(int i=0;i<=n; i++)
        for(int j=0; j<=make; j++)
        {
            dp[i][j]=-1;
        }

        cout<<call(0,make)<<endl;


    }



}

