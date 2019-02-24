#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int check(int N,int pos){ return N&(1<<pos);}
int Set(int N,int pos){ return N=(N|(1<<pos));}
int Reset(int N,int pos){ return N=(N & ~(1<<pos));}

int arr[16][16];

int dp[1<<15+2];
int n;
int bit_mask(int mask)
{
    if(mask>=((1<<n)-1))
        return 0;

    if(dp[mask]!=-1)
        return dp[mask];

    int mn=(1<<30);

    for(int i=0;i<n;i++)
    {
        int price;
        int ret;

        if(!check(mask,i))
        {
            price=arr[i][i];

            for(int j=0;j<n;j++)
            {
               if(check(mask,j) && i!=j)
                 price=price+arr[i][j];
            }

           ret=price+bit_mask(Set(mask,i));
           cout<<mn<<endl;
           mn=min(mn,ret);
        }
    }
    return dp[mask]=mn;


}


int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        scanf("%d",&n);

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        int res=bit_mask(0);

        printf("%d\n",res);
    }



    return 0;
}

