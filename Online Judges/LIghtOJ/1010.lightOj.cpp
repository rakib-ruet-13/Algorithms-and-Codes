#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    long long int tc,n,m,i,ans;
    scanf("%lld",&tc);
    for(i=1;i<=tc;i++)
    {
        scanf("%lld %lld",&n,&m);

        if(m==1)
            ans=n;
        else if(n==1)
            ans=m;
        else if(n==2)
        {
            ans=(m/4)*4;
            if(m%4==1)
                ans=ans+2;
            else if(m%4>1)
                ans=ans+4;
        }
         else if(m==2)
        {
            ans=(n/4)*4;
            if(n%4==1)
                ans=ans+2;
            else if(n%4>1)
                ans=ans+4;
        }
        else
            ans=(((n*m)+1)/2);

            printf("Case %lld: %lld\n", i, ans);
    }
    return 0;
}
