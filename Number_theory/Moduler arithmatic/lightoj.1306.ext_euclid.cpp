#include<iostream>
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007


using namespace std;


ll x,y;

ll Ext_euclid(ll a,ll b)
{

    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }

    ll gcd=Ext_euclid(b,a%b);

    ll x1=y;
    ll y1=x-(a/b)*y;

    x=x1;
    y=y1;

    return gcd;


}

ll Mod_inverse(ll n)
{
    Ext_euclid(n,mod);

    if(x<0)
        x=x+mod;

    return x;


}




int main()
{

    int tc;
    long long A,B,C,x1,x2,y1,y2;

    scanf("%d",&tc);

    for(cs=0;cs<=tc;cs++)
    {

    }




}

