#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int arr[200][200];


int main()

{
    int n;
    int m;

    long long val,min,mx;

    mx=-111;

    cin>>n>>m;

    for(int i=0;i<n;i++)
    {



         min=10000000000000;
        for(int j=0;j<m;j++)
        {
            cin>>val;
            if(val<min)
                min=val;


        }

        if(min>mx)
            mx=min;

    }

    cout<<mx<<endl;


}
