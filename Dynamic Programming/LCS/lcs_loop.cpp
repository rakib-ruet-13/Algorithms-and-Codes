#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define Max 1001


int dp[Max][Max];


int lcs(string str1,string str2)
{
    string s1;
    string s2;
    s1+="0";
    s2+="0";

    s1+=str1;
    s2+=str2;

    int l1=str1.size();
    int l2=str2.size();

    for(int i=0; i<=l1 ;i++ )
        for(int j=0 ; j<=l2 ; j++)
    {
        dp[i][j]=0;
    }

    for(int i=1 ;i<=l1 ;i++)
        for(int j=1 ; j<=l2 ;j++)
    {
        if(s1[i]==s2[j])
        {
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[l1][l2];
}


int main()
{
    string str1,str2;

    while(cin>>str1>>str2)
    {
        cout<<lcs(str1,str2)<<endl;
    }
}
