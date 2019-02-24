#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll rev(ll n)
{

    ll res=0;

    while(n!=0)
    {
        ll dig=n%10;

        res=res*10+dig;
        n=n/10;
    }

    return res;
}

int main()
{

    int tc;

    scanf("%d",&tc);
    for(int cs=1 ; cs<= tc ; cs++)
    {
        ll n;
        scanf("%lld",&n);

        ll p=rev(n);



        printf("Case %d: ",cs);

        if(p==n)
            printf("Yes\n");
        else
            printf("No\n");
    }




    return 0;
}
