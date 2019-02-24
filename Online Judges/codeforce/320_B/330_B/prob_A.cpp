#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[200][400];

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*m;j++)
            cin>>arr[i][j];
    }
   int cnt=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*m;j+=2)
        {
            if(arr[i][j] || arr[i][j+1])
            cnt++;

        }
    }

    cout<<cnt<<endl;


}
