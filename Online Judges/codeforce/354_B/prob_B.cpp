#include<bits/stdc++.h>
#include<iostream>

#define pi acos(-1.000)
#define ll long long
#define rep(i,a,b) for(int i=a; i<=b ;i++)
#define pb push_back

int power(int a,int b)
{
    if(b==0)
        return 1;

    int ans=1;

    for(int i=1; i<=b; i++)
        ans*=a;

    return ans;
}

using namespace std;

int main()
{

  ll n,t;
  cin>>n>>t;
   int res=0;

  for(int i=1;i<=n;i++)
  {
      if(t >= power(2,i-1))
        res+=i;
    else if(2*t>=power(2,i-1))
        res+=i-2;
  }

  cout<<res<<endl;

  return 0;
}

