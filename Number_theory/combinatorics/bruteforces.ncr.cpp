#include<iostream>
#include<bits\stdc++.h>


using namespace std;

long long ncr(long long n,long long r)
{
    long long ans=1;
    long long div=1;

    for(int i=1; i<=r; i++)
    {
        ans=ans*n;
        n--;
        div=div*i;

        long long d=__gcd(ans,div);
        div/=d;
        ans/=d;



    }

    cout<<ans<<endl;
    cout<<div<<endl;

    return ans;



}


int main()
{

    long long n,r;

    while(cin>>n>>r)
    {
        cout<<ncr(n,r)<<endl;


    }





}
