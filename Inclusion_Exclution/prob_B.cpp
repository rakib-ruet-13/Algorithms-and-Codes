#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll inf;

ll arr[100100][4];
ll dp[101000][4];
ll A[100100];
int n;

ll solve(int pos,int taken)
{

    if(taken==4)
        return 0;

    if(pos>n)
    {
        return -2*inf+2;
    }
    if(dp[pos][taken]!= -3*inf)
        return dp[pos][taken];

    ll res1,res2=-2*inf+2;

    res1=arr[pos][taken]+solve(pos,taken+1);
    res2=solve(pos+1,taken);

    return dp[pos][taken]=max(res1,res2);

}

int main()
{
    long long int p,q,r;
    cin>>n>>p>>q>>r;

    inf=2111111111111111111;

    for(int i=1; i<=n ; i++)
    {
        ll temp;
        cin>>temp;

        arr[i][1]=p*temp;
        arr[i][2]=q*temp;
        arr[i][3]=r*temp;
    }

    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=3; j++)
          dp[i][j]=-3*inf;



    cout<<solve(1,1)<<endl;


}
