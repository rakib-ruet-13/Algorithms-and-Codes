#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int arr[2000010];

int main()
{


    int n;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    long long int mid;

        mid=n/2;
    if(n>2)
    cout<<min(arr[mid]-arr[0],arr[n-1]-arr[mid])<<endl;
    else
        cout<<arr[mid]-arr[0]<<endl;


    return 0;



}
