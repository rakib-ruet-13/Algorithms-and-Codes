#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,t,num,i;

    cin>>n>>t;

    if(t<10 && t>=2)
    for(i=1;i<=n;i++)
    {
       cout<<t;

    }
    else if(t==10 && n>1)
    {
        for(i=1;i<n;i++)
        {
            cout<<1;
        }
        cout<<0;
    }
    else
        cout<<-1;

    cout<<endl;

    return 0;



}
