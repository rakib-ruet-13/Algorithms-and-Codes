/********************************************************/
/********************************************************/
/*************          RAKIB         *******************/
/************       CSE 13, RUET       ******************/
/***********          contact:           ****************/
/******     mail: rakib_cse13@outlook.com     ***********/
/*****           mobile : 01846207019           *********/
/********************************************************/
/********************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/******macros****/

#define Max 1000005
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid (x>=1 && x<=row && y>=1 && y<=col)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define inv 500000004
#define pii pair<ll,ll>

/***** useful function ****/

ll power(ll base, ll p){ ll ans=1;if(p==0)return 1;for(ll i=1;i<=p;i++)ans*=base;return ans;}
ll gcd(ll a, ll b){if(a==0)return b;gcd(b,a%b);}


int main()
{
    ll n,m;

    ll p,rem,sum1,sum2;

    cin>>n>>m;
    p=m/n;
    rem=m%n;
    n--;


    sum1= ((((n%mod)*(n+1)%mod)%mod)*(inv))%mod;
    sum1= (sum1*(p%mod))%mod;
    sum2= ((((rem%mod)*(rem+1)%mod)%mod)*(inv))%mod;

    sum2=((sum1%mod)+(sum2%mod))%mod;

    cout<<sum2<<endl;


}


