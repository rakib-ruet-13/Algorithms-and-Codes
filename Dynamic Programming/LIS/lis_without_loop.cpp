#include<iostream>
#include<bits/stdc++.h>
#define Max 100101
using namespace std;

int dir[Max];
int dp[Max];
int n;
int arr[Max];

int longest(int i,int j)
{

    if(j>n)
        return 0;

    if(dp[j]!=-1)
        return dp[j];



        int res1,res2;

        res1=res2=0;

     if(arr[i]<arr[j])
     {
         res1=1+longest(j,j+1);
     }

     res2=longest(i,j+1);

     if(res1>res2)
     {
         dir[i]=j;
     }
     else
     {

     }


     return dp[i]=max(res1,res2);
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

        cout<<longest(0,1)<<endl;

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

