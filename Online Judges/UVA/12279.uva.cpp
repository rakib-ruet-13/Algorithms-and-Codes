#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{


    long long int num, cnt ,cs=0,n;
    while(cin>>n && n)
    {
       cnt=0;
       for(int i=1;i<=n;i++)
       {
           cin>>num;
           if(num==0)
            cnt++;
       }

       cout<<"Case "<<++cs<<": ";
       cout<<(n-cnt)-cnt<<endl;

    }

}
