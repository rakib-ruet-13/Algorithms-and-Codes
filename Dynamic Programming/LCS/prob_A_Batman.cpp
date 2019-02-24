#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char str1[52],str2[52],str3[52];

int l1,l2,l3;

int dp[100][100][100];

int lcs(int i,int j,int k)
{
    if(i>=l1 || j>=l2 || k>=l3)
        return 0;

     if(dp[i][j][k]!=-1)
            return dp[i][j][k];

    if(str1[i]==str2[j] && str2[j]==str3[k])
    {


        return dp[i][j][k]=1+lcs(i+1,j+1,k+1);

    }
    else
    {
        int res1=lcs(i+1,j,k);
        int res2=lcs(i,j+1,k);
        int res3=lcs(i,j,k+1);


        res1=max(res1,res3);
        return dp[i][j][k]=max(res1,res2);
    }
}


int main()
{

    int tc;

    scanf("%d",&tc);
    getchar();

    for(int cs=1 ; cs<= tc ; cs++)
    {

         scanf("%s %s %s",str1,str2,str3);

         l1=strlen(str1);
          l2=strlen(str2);
            l3=strlen(str3);

         for(int i=0; i<=l1 ;i++)
            for(int j=0; j<=l2 ;j++)
              for(int k=0; k<=l3;k++)
         {
             dp[i][j][k]=-1;
         }

         int res=lcs(0,0,0);

         printf("Case %d: %d\n",cs,res);

    }

    return 0;
}


