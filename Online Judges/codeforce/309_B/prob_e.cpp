#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int fib[100];

    fib[0]=1;
    fib[1]=1;

    for(int i=2;i<99;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }


    int n;
    while(cin>>n && n)
    {
        cout<<fib[n]<<endl;
    }

}
