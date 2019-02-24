#include<iostream>
#include<bits/stdc++.h>


using namespace std;

long long int arr[100100];
vector<long long>vct;

int main()
{
    string str;
    long long n,k;
    cin>>n;
    cin>>k;


    for(int i=1; i<=n ;i++)
    {
        cin>>arr[i];
    }


    int sum=0;
    int mid;


    if(arr[k]==1)
        sum+=1;

    int j=k-1;
    int i=k+1;

    while(i<=n && j>=1)
    {
        if(arr[i]==1 && arr[j]==1)
        {
            sum+=2;
        }
        i++;
        j--;
    }

    while(i<=n)
    {
        if(arr[i]==1)
            sum+=1;
        i++;
    }
    while(j>=1)
    {
        if(arr[j]==1)
            sum++;
        j--;
    }

    cout<<sum<<endl;


    return 0;



}
