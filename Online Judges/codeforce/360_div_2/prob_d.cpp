#include<iostream>
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define VI vector<long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define inf 9999999999999999
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define pi acos(-1.0000)
#define pii pair<long long ,long long>
#define mp make_pair
#define mod 1000000007

using namespace std;
ll power(ll base,ll p);
ll gcd(ll a,ll b);
ll Set(ll n,ll pos);
ll Reset(ll n,ll pos);
bool check(ll n,ll pos);
ll b_mod(ll a,ll p);

VI vct;
ll arr[200101];

string str;







int main()
{
    ll n,m;
    cin>>n;
    cin>>m;

    int flag=1;

    for(int i=1;i<=n;i++)
    {
        ll ci;
        cin>>ci;
        cout<<gcd(ci,m);
        if(gcd(ci,m)!=1)
            flag=0;
    }



    if(flag==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;





    return 0;
}













ll power(ll base,ll p) {
    if(p==0) return 1;
     ll res=1;
      for(int i=1;i<=p;i++)
        res*=base;
    return res;
}

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

ll row,col;

ll Set(ll n,ll pos) { return n=n|(1<<pos);}
ll Reset(ll n,ll pos) {return n=n& ~(1<<pos);}
bool check(ll n,ll pos){ return n&(1<<pos);}


ll b_mod(ll a,ll p)
{
    if(p==0)
        return 1;

    if(p%2==0)
    {
        ll res=b_mod(a,p/2);

        return ((res%mod)*(res%mod))%mod;
    }

    else
        return ((b_mod(a,p-1)%mod)*(a%mod))%mod;
}




