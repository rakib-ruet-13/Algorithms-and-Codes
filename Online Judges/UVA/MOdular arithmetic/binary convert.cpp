#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int power(long long int base, long long int p)
{


    if(p==0)
        return 1;

    long long int sum=1;

    for(int i=1;i<=p;i++)
        sum*=base;

    return sum;

}

int main()
{
    int n;
    cin>>n;


    while(n!=0)
    {
        n=n/2;
        cout<<n%2<<endl;
    }
    cout<<1<<endl;


    string str;
    cin>>str;


    long long int sum=0;

    for(int i=0;i<str.size();i++)
        sum=sum+(str[i]-'0')*power(2,str.size()-1-i);

        cout<<sum<<endl;


    cout<<sum%131071<<endl;



}
