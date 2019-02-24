#include<iostream>
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
ll inf;

string str[100011][3];
ll cost[100011][3];

ll dp[100011][3];
int n;

ll solve(int i,int j)
{
    if(i>n)
        return 0;


    if(dp[i][j]!=-1)
     return dp[i][j];


    ll res1=inf;
    ll res2=inf;

    if(j==1)
    {
      if(str[i][j]<=str[i+1][j])
        res1=cost[i][j]+solve(i+1,j);

      if (str[i][j]<=str[i+1][j+1])
        res2=cost[i][j]+solve(i+1,j+1);
    }
    else
    {
         if(str[i][j]<=str[i+1][j])
           res1=cost[i][j]+solve(i+1,j);

        if (str[i][j]<=str[i+1][j-1])
           res2=cost[i][j]+solve(i+1,j-1);
    }

    return dp[i][j]=min(res1,res2);



}



int main()
{


    cin>>n;
    inf=1000000000000000;
    for(int i=1 ;i<=n;i++)
    {
        cost[i][1]=0;

        cin>>cost[i][2];
    }

    for(int i=1; i<=n ;i++)
    {
        string s;
         cin>>s;
         str[i][1]=s;

         reverse(s.begin(),s.end());
         str[i][2]=s;
    }


    string temp;

    for(int p=1; p<=100000;p++)
    {
        temp+='z';
    }

    str[n+1][1]=temp;
    str[n+1][2]=temp;


    for(int i=0; i<=n;i++)
        dp[i][0]=dp[i][1]=dp[i][2]=-1;

    ll res1=solve(1,1);

    for(int i=0; i<=n;i++)
        dp[i][0]=dp[i][1]=dp[i][2]=-1;

    res1=min(res1,solve(1,2));



    if(res1>=inf)
        cout<<-1<<endl;
    else
        cout<<res1<<endl;
}
