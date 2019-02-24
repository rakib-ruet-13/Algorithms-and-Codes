#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N,w,k;

struct node
{
    int ind;
    int val;
};

node arr[110];

int dp[110][110];

int solve(int pos,int taken)
{
    if(pos>N || taken>=k)
        return 0;

    if(dp[pos][taken]!=-1)
        return dp[pos][taken];

    int res1,res2;
    res1=res2=0;

    int temp=arr[pos].val;
    int next=pos+1;

     for(int i=pos+1; i<=N ; i++)
     {
         if(arr[i].ind-arr[pos].ind<=w)
         {
             temp+=arr[i].val;
             next++;
         }
         else
         {
             break;
         }
     }

     res1=temp+solve(next,taken+1);
     res2=solve(pos+1,taken);

     return dp[pos][taken]=max(res1,res2);



}

int main()
{

    int tc;
    scanf("%d",&tc);

    map<int,int>mymap;
    map<int,int> :: iterator it;

    for(int cs=1; cs<=tc ;cs++)
    {
        int n;
        scanf("%d %d %d",&n,&w,&k);


        for(int i=1; i<=n ; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);

            mymap[y]++;
        }

        N=0;

        for(it=mymap.begin() ; it!=mymap.end(); it++)
        {
            N++;
            arr[N].ind=it->first;
            arr[N].val=it->second;
        }

        for(int i=0; i<=N ; i++)
            for(int j=0; j<=k; j++)
            dp[i][j]=-1;

        int res=solve(0,0);

        printf("Case %d: %d\n",cs,res);

        mymap.clear();




    }





    return 0;
}
