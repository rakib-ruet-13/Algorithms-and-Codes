#include<iostream>
#include<bits/stdc++.h>


using namespace std;


struct node
{
    int first;
    int second;
    int pos;
};

node arr[1011];

int dp[1011];
int dir[1011];
int n;


int solve(int u)
{
    if(dp[u]!=-1)
    return dp[u];

    int mx=0;

    for(int v=u+1; v<=n;v++)
    {
        if(arr[u].first<arr[v].first && arr[u].second>arr[v].second)
        {
            int p=solve(v);

            if(p>mx)
            {
                dir[u]=v;
                mx=p;
            }
        }
    }

    return dp[u]=1+mx;
}



bool comp(node a,node b)
{
    return a.first<b.first;
}


int main()
{

    int a;
    int b;


    arr[0].first=-111111;
    arr[0].second=11111111;
    arr[0].pos=0;

    int c=1;
    while(cin>>a>>b)
    {
        arr[c].first=a;
        arr[c].second=b;
        arr[c].pos=c;

        c++;
    }

    n=c-1;


    sort(arr,arr+n+1,comp);

    for(int i=0;i<1010;i++)
        {
            dp[i]=-1;
            dir[i]=-1;
        }

    int res=solve(0);

    cout<<res-1<<endl;
    int k=0;
    while(dir[k]!=-1)
    {
        cout<<arr[dir[k]].pos<<endl;
        k=dir[k];
    }

}
