#include<iostream>
#include<bits/stdc++.h>


using namespace std;

long long factor(long long n);


long long bisection(long long a,long long n)
{
    long long b,mid;
    a=1;
    b=6*n;

    while(a<b)
    {
        mid=(a+b)/2;

        //cout<<"a="<<a<<"  "<<"b="<<b<<endl;
        long long res=factor(mid);

       // cout<<res<<endl;

        if(res==n)
        {
            return mid;
        }


        if(res>n)
        {
            b=mid;
        }
        else
        {
            a=mid+1;
        }



    }

    return -1;


}

long long factor(long long n)
{
    long long ans=0;


    long long cnt=0;

    while(n)
    {


        ans+=n/5;
        n=n/5;
    }


    return ans;



}


int main()
{

    int tc;
    scanf("%d",&tc);


    long long n;

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%lld",&n);

        long long ans=bisection(1,n);

        if(ans==-1)
            printf("Case %d: impossible\n",cs);
        else
            printf("Case %d: %lld\n",cs,ans-(ans%5));



    }

}
