#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int main()
{

    long long tc,x1,y1,x2,y2;

    scanf("%lld",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        printf("Case %d: %lld\n",cs, __gcd(abs(x2-x1),abs(y2-y1))+1);



    }



}
