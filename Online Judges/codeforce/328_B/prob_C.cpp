#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long int gcd(long long int a,long long int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);


}

int main()
{

    long long int t,a,b,ans,div;

    cin>>t>>a>>b;

    long long int l=(a*b)/__gcd(a,b);

    if(t<l)
    {
        ans=min(a,b)-1;
    }

    else if(t%l==0)
   {
       ans=(t/l) *2;
   }
   else
   {
       ans=(t/l)*2+1;
   }


    div=gcd(t,ans);

    cout<<ans/div<<"/"<<t/div<<endl;




}
