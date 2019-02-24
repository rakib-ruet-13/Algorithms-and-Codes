#include <bits/stdc++.h>
#define ll long long
#define sl(n) scanf("%lld", &n)
#define lf double
#define sf(n) scanf("%lf", &n)
#define pb push_back

using namespace std;

vector <ll> v;

int main(){


    ll x,y;
    sl(x); sl(y);
    bool f = false;
    if(x<0) f = true;
    x = abs(x);

    ll n;
    sl(n);
    lf sum = 0;
    ll rem = y;
    for( ll i = 1 ; i<=n ; i++ ){

        ll l,u; lf c;
        sl(l); sl(u); sf(c);
        rem = rem - (u-l);
        sum += (u-l)*c;
    }

    lf left=0 , right=1000000000000.0 , mid ;
    for( ll i = 0 ; i<100 ; i++ ){

        mid  = (left+right)/2.0;
        //printf("%.10f\n" , right);
        if( mid*( sum + rem ) == x ) break;
        if( mid*( sum + rem ) < x )  left = mid;
        else  right = mid;

    }
    if( f ) mid = 0.0- mid;
        printf("%.10f\n" , mid);



return 0;}


