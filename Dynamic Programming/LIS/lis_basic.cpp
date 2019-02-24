#include<iostream>
#include<bits/stdc++.h>
#define Max 100101
using namespace std;

int dir[Max];
int dp[Max];
int n;
int arr[Max];

int longest(int u)
{
    if(dp[u]!=-1)
        return dp[u];


    int maxi=0;
    for(int v=u+1; v<=n;v++)
    {
        if(arr[u]<arr[v])
        {
            if(maxi<longest(v))
            {
                maxi=longest(v);
                dir[u]=v;
            }
        }

    }

    return dp[u]=1+maxi;
}




int main()
{


    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ;cs++)
    {
        scanf("%d",&n);


        for(int i=1;i<=n ;i++)
        {
            scanf("%d",&arr[i]);
        }

        for(int i=0;i<=n;i++)
        {
            dp[i]=dir[i]=-1;
        }

        arr[0]=-1111111;

        cout<<longest(0)-1<<endl;

        int p=0;
        while(dir[p]!=-1)
        {
            cout<<arr[dir[p]]<<" ";
            p=dir[p];
        }

        cout<<endl;
    }





    return 0;
}
