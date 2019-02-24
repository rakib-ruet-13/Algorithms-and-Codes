#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tc;

    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        int n;
        scanf("%d",&n);

          int cnt1=0;
          int mx=2;

        for(int i=1; i<=n ;i++)
        {

                int val;
                scanf("%d",&val);
                cnt1+= ceil(((float)val-(float)mx)/5);
                mx=val;

        }

            printf("Case %d: %d\n",cs,cnt1);




    }





}
