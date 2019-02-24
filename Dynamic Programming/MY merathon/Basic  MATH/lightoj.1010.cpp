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
    ll ans,n,r,i,j;


    rep(cs,1,tc)
    {
        read64(i);
        read64(j);

        if(i>j)
            swap(i,j);

        if(i<=1 || j<=1)
          ans=max(i,j);

        else if(i==2 )
            {
                ans = (j / 4) * 4;
			if(j % 4 == 1)
				ans += 2;
			else if(j % 4 > 1)
				ans += 4;
            }
        else if(i%2==0 || j%2==0)
        {
            if(i%2==0 && j%2==0)
                ans=(i/2)*j;
            else if(i%2==0)
                ans=(i/2)*(j/2)+(j/2+1)*(i/2);
            else
                ans=(i/2+1)*(j/2)+(i/2)*(j/2);
        }
        else
        {
            ans=(i/2+1)*(j/2+1)+(i/2)*(j/2);

        }

        printf("Case %d: %lld\n",cs,ans);


    }

    return 0;
}

