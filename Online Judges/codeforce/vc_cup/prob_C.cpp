#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,ans1,ans2,rem1,rem2,a,b,r1,r2;

    cin>>n>>m;

    ans1=n*2;
    ans2=m*3;

    r1=r2=0;

    long long ans=max(ans1,ans2);

    rem1=ans/6;
    rem2=ans/6;

    if(rem1>0)
    {
       r1=n-rem1;
    }

    a=ans+(3*r2);

    if(rem2>0)
    {
       r2=m-rem2;
    }
    b=ans+(2*r1);

        cout<<min(a,b)<<endl;









}
