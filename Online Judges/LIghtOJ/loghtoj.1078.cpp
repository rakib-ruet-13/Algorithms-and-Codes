#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ;cs++)
    {
        long long n,dig;
        scanf("%lld %lld",&n,&dig);


        int num=0;
        int cnt=0;

        while(1)
        {
            cnt++;
            num=num*10+dig;

            if(num%n==0)
                break;
            num=num%n;
        }

        printf("Case %d: %d\n",cs,cnt);

    }


}
