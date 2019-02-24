#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int l1,l2;
string str1,str2;
int LC;

long long int dp[102][102];


long long lcs()
{
   string st1,st2;
   st1.push_back('0');
   st1+=str1;
   st2.push_back('0');
   st2+=str2;


   for(int i=0; i<=l1; i++)
    for(int j=0; j<=l2; j++)
   {
       dp[i][j]=0;
   }

   dp[0][0]=0;

   for(int i=1; i<=l1 ; i++)
   {
       for(int j=1; j<=l2; j++)
       {
           if(st1[i]==st2[j])
             dp[i][j]=dp[i-1][j-1]+1;

           else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
       }
   }





   return dp[l1][l2];

}




int main()
{
    int tc;
    scanf("%d",&tc);
    getchar();

    for(int cs=1; cs<= tc ;cs++)
    {
        getline(cin,str1) ;

        str2=str1;
        reverse(str2.begin(),str2.end());


        l1=str1.size();
        l2=str2.size();

        LC=lcs();




        printf("Case %d: %d\n",cs,l1-LC);

    }

    return 0;
}
