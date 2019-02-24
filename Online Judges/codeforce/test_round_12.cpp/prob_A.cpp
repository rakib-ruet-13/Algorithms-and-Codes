#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int a,b,k;

    cin>>k;
    cin>>a;
    cin>>b;


    if(a>b)
    swap(a,b);
    if(a<0 && b<0)
    {
        cout<<abs(a)/k-abs(b)/k+1<<endl;

    }
    else if(a<0)
    {
        cout<<abs(a)/k+b/k<<endl;
    }
    else
    {
        cout<<b/k-a/k+1<<endl;
    }




}
