#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b ;i++)
#define pb push_back
#define read64(x) scanf("%lld",&x)
#define read32(x) scanf("%d",&x)
#define ll long long
#define mod 1e9+7
#define pi acos(-1.000)
#define Max 1010


using namespace std;

int main()
{
    string str;
    int tc;
    read32(tc);

    rep(cs,1,tc)
    {
        ll div;
        cin>>str;
        read64(div);
        ll num=0;
        rep(i,0,str.size()-1)
        {
          if(str[i]=='-')
                continue;
          num=num*10+(str[i]-'0');
          num=num%div;
        }

        if(num==0)
            printf("Case %d: divisible\n",cs);
            else
            printf("Case %d: not divisible\n",cs);
    }

    return 0;



}
