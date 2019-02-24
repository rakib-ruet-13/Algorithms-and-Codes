#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int check(int N,int pos){ return N&(1<<pos);}
int Set(int N,int pos){ return N=(N|(1<<pos));}
int Reset(int N,int pos){ return N=(N & ~(1<<pos));}

int health[18];
char damage[18][18];

int dp[1<<17];
int n;


int select_weapon(int mask,int pos)
{

    int res=1;

    for(int i=0; i<n ; i++)
    {
        if(check(mask,i))
            res=max(res,(int)(damage[i][pos]-'0'));
    }

    cout<<"mask = "<<mask<<" pos = "<<pos<<"  res= "<<res<<endl;

    return res;


}


int solve(int mask)
{


    if(mask== ((1<<n) -1))
        return 0;

    if(dp[mask]!=-1)
        return dp[mask];

   int mn=1000000;



    for(int i=0; i<n; i++)
    {


        if( !check(mask,i))
        {
            int p=select_weapon(mask,i);

            mn=min(mn,(int) ceil((float)health[i]/(float)p) + solve(Set(mask,i)));

        }

    }

    return dp[mask]=mn;

}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        scanf("%d",&n);

        for(int i=0; i<n ; i++)
        {
            scanf("%d",&health[i]);
        }

        for(int j=0; j<n ; j++)
        {
            getchar();

            for(int k=0; k<n ; k++)
        {
            scanf("%c",&damage[j][k]);
        }

        }

        memset(dp,-1,sizeof(dp));


        printf("Case %d: %lld\n",cs,solve(0));


    }





    return 0;
}
