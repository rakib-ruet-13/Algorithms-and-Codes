#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int check(int N,int pos){ return N&(1<<pos);}
int Set(int N,int pos){ return N=(N|(1<<pos));}
typedef long long ll;

long long GCD(long long a, long long b)
{
    if(a%b==0)
        return b;
    else
        return(b,a%b);
}


int main()
{
    int tc;

    long long inf= 11111111111111;

    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {

        long long int n,m;
        scanf("%lld %lld",&n,&m);

        long long int arr[18];

        for(int i=0; i<m; i++)
            scanf("%lld",&arr[i]);


         long long int res=0;

         long long p=m;
         p=(1<<p)-1;

        for(int i=1; i<=p ; i++)
        {

        ll lcm=1;
        ll cnt=0;

        for(int k=0; k<m; k++)
        {
            if(check(i,k))
            {
                cnt++;

                if(lcm<=inf)
                   lcm= lcm*(arr[k])/__gcd((int)lcm,(int)arr[k]);

            }
        }

        if(cnt%2==0)
            res-=(n/lcm);
            else
                res+=(n/lcm);

        }

        printf("Case %d: %lld\n",cs,n-res);

    }



    return 0;
}
