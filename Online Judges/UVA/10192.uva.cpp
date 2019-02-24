#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string str1,str2;
int dp[1001][1001];

int LCS(int m,int n)
{
    int i,j;
    for(i=0;i<=m;i++)
        dp[i][0]=0;
    for(j=0;j<=n;j++)
        dp[0][j]=0;

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
    {
        if(str1[i-1]==str2[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }

    return dp[m][n];

}

int main()
{

  int l1,l2,c,cs=1;

  while(getline(cin,str1) && str1[0]!='#')
  {
      getline(cin,str2);
       l1=str1.size();
       l2=str2.size();
       c=LCS(l1,l2);

      cout<<"Case #"<<cs++<<": you can visit at most "<<c<<" cities."<<endl;

  }
return 0;
}
