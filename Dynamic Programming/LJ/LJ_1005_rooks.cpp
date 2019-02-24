#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

long long npr(long long n, long long r)
{
    if(r>n)
        return 0;

    long long res=1;

    for(int i=1 ; i<=r; i++)
        res*=(n-i+1);

    return res;
}

long long ncr(long long n, long long r)
{


    long long res1=1;
    long long res2=1;

    for(int i=1; i<=r ; i++)
    {
        res1*=(n-i+1);

        res2*=i;

        long long div=gcd(res1,res2);

        res1/=div;
        res2/=div;
    }

    return res1/res2;
}

int main()
{
    int tc;

    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        if(k>n)
        {
             printf("Case %d: %lld\n",cs,0LL);
        }
        else
        printf("Case %d: %lld\n",cs,npr(n,k)*ncr(n,k));


    }



    return 0;
}
