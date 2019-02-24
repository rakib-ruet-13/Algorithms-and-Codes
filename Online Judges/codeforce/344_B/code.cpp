#include<iostream>
#include<bits/stdc++.h>

using namespace std;


typedef long long ll;


int main()
{

     int tc;
     scanf("%d",&tc);
     long long n;

     string str;

     for(int cs=1 ; cs<=tc ;cs++)
     {
         scanf("%lld",&n);
         n=n-1;

         n=(n*(n+1))/2;

         printf("Case %d: %lld\n",cs,n);
     }
     return 0;


}
