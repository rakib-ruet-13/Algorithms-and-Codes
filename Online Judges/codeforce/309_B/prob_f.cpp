#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long int gcd(long long int a,long long int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);


}

int main()
{


    long long int n,k,u,v;

    while(cin>>n>>k)
    {
        u=1;v=1;
        for(long long int i=0;i<k;i++)
        {
            u=u*(n-i);
            v=v*(k-i);

            long long int k=gcd(u,v);
            u=u/k;
            v=v/k;
        }

        cout<<u/v<<endl;



    }


}
