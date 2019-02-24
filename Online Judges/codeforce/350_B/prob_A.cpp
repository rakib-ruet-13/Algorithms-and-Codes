#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long n;

    cin>>n;

    long long res,mod,res1;

    res=(n/7)*2;
    res1=(n/7)*2;
    mod=n%7;

    if(mod==1)
        res+=1;

    if(mod>1)
        res+=2;

    if(mod==6)
        res1+=1;


    cout<<res1<<" "<<res<<endl;


}
