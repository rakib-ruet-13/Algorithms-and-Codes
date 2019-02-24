#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    int n,m;

    cin>>n;
    cin>>m;

    if(n>m)
        swap(n,m);



    long long res=0;


    for(int i=1; i<=n;i++)
    {
       res+=((m+i)/5-(i/5));
    }

    cout<<res<<endl;
}
