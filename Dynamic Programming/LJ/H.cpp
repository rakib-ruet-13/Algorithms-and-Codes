#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll b, ll p)
{
    ll r, y, t;
    if(p==0)
        r=1;
    else if(p%2==0)
    {
        y = power(b, p/2);
        r = y*y;
    }

    else
    {
        y = power(b, p/2);
        t = y*y;
        r = t*b;
    }

    return r;
}
int main()
{

    ll n, p, i, j, l, r, x, y, d1, d2;
    char s1[100], s2[100];
    scanf("%lld", &n);
    scanf(" %s", s1);
    scanf(" %s", s2);
    p = power((ll)2, n);

    for(i=0; i<n; i++)
    {
        d1 = s1[i]-48;
        d2 = s2[i]-48;
        if(i==0)
        {
            if(d1==0)
            {
                x=1;
                l=0;
            }
            else
            {
                x=p/2+1;
                l=1;
            }

            if(d2==0)
            {
                y=p/2;
                r=0;
            }
            else
            {
                y=p;
                r=1;
            }
            p/=2;

        }

        else
        {
            if(d1==0)
            {
                if(l==0)
                {
                    x=x;
                    l=0;
                }
                else
                {
                    x+=(p/2);
                    l=1;
                }

            }
            else
            {
                if(l==0)
                {
                    x+=(p/2);
                    l=1;
                }
                else
                {
                    x=x;
                    l=0;
                }
            }




            if(d2==0)
            {
                if(r==0)
                {
                    y-=(p/2);
                    r=0;
                }
                else
                {
                    y=y;
                    r=1;
                }

            }
            else
            {
                if(r==0)
                {
                    y=y;
                    r=1;
                }
                else
                {
                    y-=p/2;
                    r=0;
                }
            }
            p/=2;
        }

    }

    printf("%lld\n", y-x-1);

    return 0;
}

