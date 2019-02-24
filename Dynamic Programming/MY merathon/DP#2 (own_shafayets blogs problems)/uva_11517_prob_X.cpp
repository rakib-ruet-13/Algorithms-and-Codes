#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct coin
{
    ll val;
    ll num;
};

ll inf=(1<<30);

ll n,c[110],make;

coin dp[110][21000];

coin solve(ll pos,ll curr)
{
    if(pos>=n+1)
    {
        coin p;

        if(curr>=make)
        {
            p.val=curr;
            p.num=0;

            return p;
        }

        else
        {
            p.val=inf;
            p.num=inf;

            return p;
        }

    }


    if(dp[pos][curr].num!=-1)
        return dp[pos][curr];

    coin res1,res2;

    res1.num=res2.num=inf;
    res1.val=res2.val=inf;

    if(curr<make)
    {
        coin p=solve(pos+1,curr+c[pos]);
        res1.num=1+p.num;
        res1.val=p.val;
    }

    res2=solve(pos+1,curr);

             if(res1.val==res2.val)
            {
              if(res1.num>res2.num)
                return dp[pos][curr]=res2;
              else
                return dp[pos][curr]=res1;
            }

            if(res1.val<res2.val)
                return dp[pos][curr]=res1;
            else
              return dp[pos][curr]=res2;






}

int main()
{


    int tc;

    cin>>tc;

    while(tc--)
    {
        cin>>make;
        cin>>n;

        ll mx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            mx=max(mx,c[i]);
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=make+mx; j++)

                dp[i][j].num=dp[i][j].val=-1;
        }

        coin res;
        res=solve(1,0);

        cout<<res.val<<" "<<res.num<<endl;
    }

    return 0;
}
