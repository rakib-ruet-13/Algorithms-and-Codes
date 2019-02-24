#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long int dp[2000001];
long long int dir[2000001];
long long int arr[2000001];
int n;

long long int longest(int u)
{
    if(dp[u]!=-1)
        return dp[u];


    long long int mx=0;

    for(int v=u+1; v<=n ;v++)
    {

        long long int p=0;

        if(arr[u]<arr[v])
        {
            p=longest(v);

            if(p>=mx)
           {
            mx=p;
            dir[u]=v;
           }

        }

    }

    return dp[u]=1+mx;



}



int main()
{

    int a;

    arr[0]=-99999999999999;
    n=0;

    for(int i=0;i<=2000000;i++)
        dp[i]=dir[i]=-1;

    while(scanf("%d",&a)==1)
    {
       arr[++n]=a;
    }


    long long res=longest(0)-1;

    cout<<res<<endl;
    cout<<"-"<<endl;
    int k=0;
    while(dir[k]!=-1)
    {
        cout<<arr[dir[k]]<<endl;
        k=dir[k];
    }




}
