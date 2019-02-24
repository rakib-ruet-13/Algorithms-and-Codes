#include<iostream>
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
ll mod;

long long mult(long long int n,long long int p,long long int m);

ll gcd2(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return gcd2(b,a%b);
}


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


ll mod_inverse(ll n)
{
     ll gcd=Ext_euclid(n,mod);

    if(x<0)
    {
        x=x+mod;
    }

    return x;
}



int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {

    long long A;


    scanf("%lld %lld",&A,&mod);

    //cout<<gcd(A,mod)<<endl;


    if(A==1)
    {
        printf("%lld\n",mod-1);
    }
    else if(gcd2(A,mod)!=1 )
        printf("-1\n");
    else
    {
        //cout<<"ok"<<endl;
        mod_inverse(A);
        printf("%lld\n",x);
    }
    }




  return 0;


}













long long mult(long long int n,long long int p,long long int m)
{
    if(p==0)
        return 0LL;

    else if(p%2==1)

        {
            return ((n%m)+ mult(n,p-1,m))%m;
        }
    else
        {
            ll temp=mult(n,p/2,m);
            return (temp+temp)%m;

        }

}







