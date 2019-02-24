#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define Max 1001


int dp[Max][Max];
string dps[Max][Max];

vector<string>vct;
string ans;

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
        dps[i][j].clear();
    }

    for(int i=1 ;i<=l1 ;i++)
        for(int j=1 ; j<=l2 ;j++)
    {
        if(s1[i]==s2[j])
        {
            dp[i][j]=dp[i-1][j-1]+1;
            dps[i][j]=dps[i-1][j-1]+s1[i];
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                  dp[i][j]=dp[i-1][j];
                  dps[i][j]=dps[i-1][j];
            }
            else if(dp[i-1][j]<dp[i][j-1])
            {
                  dp[i][j]=dp[i][j-1];
                  dps[i][j]=dps[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                 dps[i][j]=min(dps[i][j-1],dps[i-1][j]);
            }


        }
    }


    ans=dps[l1][l2];

     for(int i=1 ;i<=l1 ;i++)
        for(int j=1 ; j<=l2 ;j++)
        {
            if(dp[i][j]==dp[l1][l2])
            {
                if(dps[i][j]<ans)
                    ans=dps[i][j];
            }
        }


    return dp[l1][l2];
}



int main()
{

    int tc;

    scanf("%d",&tc);
    getchar();

    string st,str1,str2;

    for(int cs=1 ; cs<= tc ; cs++)
    {

        cin>>str1;
        cin>>str2;



       int len=lcs(str1,str2);

       // cout<<len<<endl;

        if(len==0)
        {
            printf("Case %d: :(\n",cs);
        }
        else
        {
             printf("Case %d: ",cs);
             cout<<ans<<endl;

        }
        ans.clear();
    }

    return 0;
}




