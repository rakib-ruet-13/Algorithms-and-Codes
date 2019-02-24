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


    cin>>a>>b;

    long long gcd=Ext_euclid(a,b);

    printf("%lld * a + % lld *b == %lld\n",x,y,gcd);





}
