#include<iostream>
#include<bits/stdc++.h>

#define mod 1000000007
#define Max 1000000

typedef  long long int ll;

ll arr[1001][1001];

using namespace std;

int main()
{

    arr[1][1]=1;

    for(int i=0;i<=1000;i++)
        for(int j=0;j<=i;j++)
    {
        if(j==0 || j==i)
          arr[i][j]=1;

        else
        {
            arr[i][j]=(arr[i-1][j-1]%mod+arr[i-1][j]%mod)%mod;
        }
    }

    int n,r;

    while(cin>>n>>r)
    {
        cout<<arr[n][r]<<endl;
    }




}
