#include<iostream>
#include<bits/stdc++.h>

using namespace std;



typedef  long long ll;

ll inf=111111111111;

ll coinx[50];
ll coiny[50];

ll dp[50][302][302];
ll n;
ll val;

long long int solve(ll pos,ll x,ll y)
{
    //cout<<x<<" "<<y<<" "<<val<<" "<<pos<<endl;
    if(pos>=n+1)
    {
        //cout<<"in"<<endl;

        if( x*x+y*y== val*val)
            return 0;
        else
            return inf;
    }
    if(x*x+y*y>val*val)
        return inf;

    if(dp[pos][x][y]!=-1)
        return dp[pos][x][y];


    long long res1,res2;

    res1=res2=inf;

    if( ((x+coinx[pos])*(x+coinx[pos]))+ ((y+coiny[pos])*(y+coiny[pos])) <= val*val )
        res1=1+solve(pos,x+coinx[pos],y+coiny[pos]);

    res2=solve(pos+1,x,y);

    return dp[pos][x][y]=min(res1,res2);


}


int main()
{
    int tc;
    scanf("%d",&tc);

    while(tc--)
    {
        cin>>n>>val;

        for(int i=1;i<=n;i++)
        {

            cin>>coinx[i]>>coiny[i];

        }


        for(int i=0;i<=n;i++)
            for(int j=0;j<=val;j++)
                for(int k=0;k<=val; k++)
            dp[i][j][k]=-1;

        long long res=solve(1,0,0);

        if(res<inf)
            cout<<res<<endl;
        else
            cout<<"not possible\n";
    }

}
