#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int tc,t,d,s;

    scanf("%lld",&tc);

    for(int i=1; i<=tc ;i++)
    {
        scanf("%lld %lld %lld",&t,&d,&s);

        if(t==0)
            printf("Impossible\n");
        else
            printf("%lld Seconds\n",(long long) (ceil((double)d/(double)t))*s);
    }
}
