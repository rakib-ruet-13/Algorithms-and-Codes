#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll base,ll p)
{
    if(p==0)
        return 1;

    ll ans=1;

    for(int i=1;i<=p;i++)
        ans*=base;

    return ans;
}


ll fun(ll n,ll b,ll c,ll a)
{
    ll ans=0;

    while(n/b!=0)
    {
        ans+=n/b;
        n=(n%b)+(n/b)*c;
    }

    ans+=(n%b)/a;

    return ans;


}


int main()
{
    long long n,a,b,c;
    long long ans1,ans2,rem;

    ll ans3=0;

    cin>>n>>a>>b>>c;


        ans3=(n/b);
        rem=n%b+(n/b)*c;
        ans3+=(rem/a);


         ans2=0;
         ans2+=fun(n,b,c,a);



         ans1=n/a;
         ll r2=n%a;
         ans1+=fun(r2,b,c,a);





    ans2=max(ans3,ans2);
    cout<<max(ans1,ans2)<<endl;



}
