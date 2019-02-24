#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    int arr[100000];

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    int m=0;
    int k=n-1;
    for(int i=1 ;i<=n ;i++)
    {
        if(i==1)
            cout<<arr[m++];
        else if(i%2==1)
            cout<<" "<<arr[m++];
        else
            cout<<" "<<arr[k--];
    }

    cout<<endl;
}
