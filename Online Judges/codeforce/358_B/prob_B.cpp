#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int arr[1000010];

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n ;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);



    int p=1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>=p)
            p++;

    }

    cout<<p<<endl;


}
