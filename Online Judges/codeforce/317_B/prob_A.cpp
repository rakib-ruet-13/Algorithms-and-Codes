#include<iostream>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

 long long int arr[1000001],arr2[1000001];
int main()
{


    long long int n,m,k,l,i,j;

    cin>>n>>m;
    cin>>k>>l;

    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<m;i++)
        cin>>arr2[i];

    if(arr[k-1]<arr2[m-l])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;



    return 0;
}
