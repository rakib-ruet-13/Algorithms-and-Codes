#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long mod;

int main()
{
    long long tc,a,b,c,res;
    scanf("%d",&tc);
    mod=1000000007;

    for(int cs=1 ;cs<=tc ; cs++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);

        if(c==1)
        printf("%lld\n",b);

        else
        {
            for(int i=2 ;i<=c;i++)
            {
                if(i>500)
                    break;
                res=(a+b)%mod;
                a=b;
                b=res;

            }

            printf("%lld\n",res);
        }

    }


}
