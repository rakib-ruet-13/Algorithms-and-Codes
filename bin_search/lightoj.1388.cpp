#include<iostream>
#include<bits/stdc++.h>


using namespace std;


long long power(long long base,long long p)
{
    long long res=1;

    for(int i=1; i<=p ;i++)
    {
        res*=base;
    }
    return res;
}


long long fun(long long n)
{
    long long cnt=0;

    for(int i=1 ; power(5,i)<=n ;i++)
    {
        cnt+=n/power(5,i);
    }
   // cout<<cnt<<endl;
    return cnt;


}


int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        long long int n,ll,ul;
        scanf("%lld",&n);

        ll=1;
        ul=5*10000000000;



        long long  mid=(ll+ul)/2;


        while(ll<ul)
        {
           // cout<<ll<<" "<<ul<<endl;

            if(ll+1==ul)
            {
                if(fun(ll)==n)
                    break;
                else
                {
                    ll=ul;
                    break;
                }
            }
            if(fun(mid)>=n)
              ul=mid;
            else
              ll=mid;

            mid=(ll+ul)/2;

            //getchar();
        }

        printf("Case %d: ",cs);

        if(fun(ll)!=n)
            printf("impossible\n");
        else
            printf("%lld\n",ll);

    }



    return 0;
}
