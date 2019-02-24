#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int arr[2000010];

int main()
{
    long long int n,temp=0,ans=0;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];


            ans+=abs(arr[i]-temp);
            temp=arr[i];
    }


    cout<<ans<<endl;







    return 0;
}

