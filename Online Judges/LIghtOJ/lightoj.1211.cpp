#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{

    long long int a,b,c,d,e,f;
    long long int x,y,z,p,q,r;

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        int n;
        scanf("%d",&n);

        a=b=c=0;
        d=e=f=10000;


            for(int i=1; i<=n ;i++)
            {
                scanf("%lld %lld %lld %lld %lld %lld",&x,&y,&z,&p,&q,&r);

                a=max(a,x);
                b=max(b,y);
                c=max(c,z);

                d=min(d,p);
                e=min(e,q);
                f=min(f,r);
            }

        long long res;

        if(d<a || e<b || f<c )
          res=0;
        else
        {
            res=abs((a-d)*(b-e)*(c-f));
        }


        printf("Case %d: %lld\n",cs,res);



    }


}
