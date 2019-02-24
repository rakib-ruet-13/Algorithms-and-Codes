#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    long long int n,a,p;

    cin>>n;

    long long int m=10000000000,sum=0;

    for(int i=0;i<n;i++)
    {
        cin>>a>>p;

        m=min(m,p);
        sum+=m*a;

    }
    cout<<sum<<endl;


}
