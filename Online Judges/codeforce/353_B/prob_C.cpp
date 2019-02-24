#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long arr[100010];
long long sum[110000];

int main()
{
    long long n;
    long long res;


    cin>>n;

    for(int i=1; i<=n ;i++)
    {
        cin>>arr[i];
    }


    int mx=-11111;
     for(int k=1; k<= n; k++)
    {
        if(arr[k]>=mx)
        {
            mx=arr[k];

        }

    }



    cout<<mx<<endl;

    return 0;
}

