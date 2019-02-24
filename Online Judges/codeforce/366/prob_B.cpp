#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define uu first
#define vv second
#define mem(x,val) memset(x,val,sizeof(x))
#define REP(i,n) for(int i=1; i<=n ;i++)
#define rep(n) for(int i=0; i<n;i++)
#define pi acos(-1.0000)
#define all(x) (x.begin(),x.end())
#define Max 100100


using namespace std;

ll power(ll base,ll p){ if(p==0) return 1; ll ans=1 ; for(ll i=1; i<=p; i++) ans*=base ; return ans ;}



int main()
{

    int n;

    cin>>n;

    for(int i=1; i<=n ;i++)
    {

        if(i%2==1)
            printf("I hate");
        else
            printf("I love");

        if(i==n)
            printf(" it");
        else
            printf(" that ");

    }

    printf("\n");



    return 0;
}

