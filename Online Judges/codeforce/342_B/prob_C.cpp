#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int main()
{

    int arr[510][510];
    int n,k;
    cin>>n>>k;

    int cnt=0;
    long long sum=0;
    for(int i=1 ;i<=n;i++)
    {
        for(int j=1;j<k;j++)
        {
            arr[i][j]=++cnt;

        }
    }

    //cout<<sum<<endl;

    for(int i=1 ;i<=n;i++)
    {
        for(int j=k;j<=n;j++)
        {
            arr[i][j]=++cnt;
            if(j==k)
                sum+=cnt;
        }


    }

    cout<<sum<<endl;

     for(int i=1 ;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==1)
                cout<<arr[i][j];
            else
                cout<<" "<<arr[i][j];

        }

        cout<<endl;


    }




}
