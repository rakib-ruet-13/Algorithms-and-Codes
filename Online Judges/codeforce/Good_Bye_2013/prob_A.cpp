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

#define Max 1000001
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid (x>=1 && x<=row && y>=1 && y<=col)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define pii pair<ll,ll>

/***** useful function ****/

ll power(ll base, ll p){ ll ans=1;if(p==0)return 1;for(ll i=1;i<=p;i++)ans*=base;return ans;}
ll gcd(ll a, ll b){if(a==0)return b;gcd(b,a%b);}


/***** Nececessary global variables ****/
ll row,col;


int main()
{

    int n;
    string s,s1;

    cin>>n>>s1>>s;

    if(s=="week")
    {
        if(n==5 || n==6)
            cout<<53<<endl;
        else
            cout<<52<<endl;
    }

    else
    {
        if(n<=29)
            cout<<12<<endl;
        else if(n==30)
            cout<<11<<endl;
        else
            cout<<7<<endl;

    }

    return 0;





     return 0;


}





