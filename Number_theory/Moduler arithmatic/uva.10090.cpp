#include<iostream>
#include<bits/stdc++.h>


using namespace std;


long long x,y;

long long Ext_euclid(long long  a,long long b)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }

    long long res=Ext_euclid(b,a%b);
    long long x1=y;
    long long y1=x-(a/b)*y;

    x=x1;
    y=y1;

    return res;

}


int main()
{

    long long int a,b;

    long long n,c1,c2;

    while(cin>>n && n)
    {
        cin>>c1>>a;
        cin>>c2>>b;


        long long gcd=Ext_euclid(a,b);

        if(n%gcd!=0)
            printf("failed\n");
        else
            printf("%lld %lld\n",x,y);



    }





}


