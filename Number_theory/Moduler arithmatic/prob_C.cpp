#include<iostream>
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
ll mod1;


ll gcdg(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return gcdg(b,a%b);
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


long long mod(long long int n,long long int p,long long int m)
{
    if(p==0)
        return 1LL;
    else if(p%2==1)

        {
            return mult(n,mod(n,p-1,m),m);
        }
    else
        {
            ll temp=mod(n,p/2,m);
             return mult(temp,temp,m);
        }

}





int main()
{

    int tc;
    scanf("%d",&tc);

    //cout<<mult(10,10,200)<<endl;

    for(int cs=1; cs<=tc ;cs++)
    {

    long long A;


    scanf("%lld %lld",&A,&mod1);

    if(gcdg(max(A,mod1),min(A,mod1))!=1)
        printf("-1\n");
    else
    {
        ll x=mod(A,mod1-2,mod1);
        printf("%lld\n",x);
    }
    }

  return 0;

}

