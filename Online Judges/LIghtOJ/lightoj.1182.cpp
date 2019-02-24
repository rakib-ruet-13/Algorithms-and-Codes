#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool check (long long int n,int pos) { return n&(1<<pos); }


int main()
{
    int tc;

    scanf("%d",&tc);

    for(int cs=1; cs<=tc ; cs++)
    {
        long long int n;


        scanf("%lld",&n);

        int cnt=0;
        for(int i=0; i<31;i++)
        {
           if(check(n,i)==true)
            {
                //cout<<1;
                cnt++;
            }

        }

        if(cnt%2==0)
            printf("Case %d: even\n",cs);
        else
            printf("Case %d: odd\n",cs);

    }

    return 0;
}

