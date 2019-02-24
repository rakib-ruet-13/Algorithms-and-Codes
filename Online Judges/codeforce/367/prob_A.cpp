#include<iostream>
#include<bits/stdc++.h>
#define Max 500000

using namespace std;

typedef long long ll;

int main()
{
    ll n;

    double a,b;
    double t,x,y,v;
    double mx=100000000000000;


    cin>>a>>b;
    cin>>n;

    for(int i=1; i<=n ;i++)
    {
        cin>>x>>y>>v;

        double s= sqrt((a-x)*(a-x)+(b-y)*(b-y));

       mx=min(mx, s/v );
    }


    printf("%.10lf\n",mx);






    return 0;
}
