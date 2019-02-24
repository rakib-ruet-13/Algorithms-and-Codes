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
    int tc;
    read32(tc);
    int ans,n,r,i,j;


    char s[10];
    rep(cs,1,tc)
    {
        scanf("%d %s",&n,s);



        if(s[0]=='B')
        {
                if(n%3!=0)
                 printf("Case %d: Bob\n",cs);
                else
                     printf("Case %d: Alice\n",cs);


        }
        else
        {


            if(n%3==1)
                 printf("Case %d: Bob\n",cs);
            else
                 printf("Case %d: Alice\n",cs);

        }
    }

    return 0;
}
