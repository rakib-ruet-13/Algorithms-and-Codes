#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int cs=1 ; cs<=tc ; cs++)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);

        if(a>b)
            swap(a,b);


        ll res1= (b/3)*2;
        if(b%3==2)
            res1++;

        ll res2=((a-1)/3)*2;

        if((a-1)%3==2)
            res2++;





        printf("Case %d: %lld\n",cs,res1-res2);
    }


}
