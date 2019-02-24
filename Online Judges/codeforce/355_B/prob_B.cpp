#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int arr[100100];
int main()
{
    long long int n,h,k;
    cin>>n>>h>>k;


    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    long long int j=0;
    long long int rem=0;
    long long int res=0;

    while(1)
    {
        if(j>=n && rem<=0)
            break;

        while( j<n && arr[j]+rem<=h)
        {
            rem=rem+arr[j];
            j++;
        }


        if(rem<k)
        {
            res++;
            rem=0;
        }
        else
        {
            res+=rem/k;
            rem=rem%k;
        }
    }


    cout<<res<<endl;

}

