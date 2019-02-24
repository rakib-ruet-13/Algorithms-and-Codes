#include<iostream>
#include<bits/stdc++.h>
#define inf (1<<31)
using namespace std;

vector<int> vct;
int n;
int dp[32769];

int calc(int u)
{

    if(dp[u]!=-1)
    {
        return dp[u];
    }

    int mx=0;

       for(int v=u+1 ; v<n ;v++)
        {
            if(vct[u]>=vct[v])
            {
               int  p=calc(v);


                   if(p>mx)
                   mx=p;
            }


        }

        return dp[u]=1+mx;
}


int main()
{
    int cs=1;
    int a;

    while(cin>>a && a!=-1)
    {
        vct.push_back(10000000);
        vct.push_back(a);

        while(cin>>a)
        {
            if(a==-1)
                break;
            else
                vct.push_back(a);
        }

        n=vct.size();

        for(int i=0;i<=n;i++)
            dp[i]=-1;


        if(cs!=1)
            printf("\n");


        printf("Test #%d:\n",cs);
        printf("  maximum possible interceptions: %d\n",calc(0)-1);


        cs++;
        vct.clear();


   }




    return 0;
}
