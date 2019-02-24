#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        double n;
        scanf("%lf",&n);

        double res=1;

        int ans;

        for(int i=1; i<=1000000; i++)
        {
            res*=(n-i);
            res*=(1/n);

            if(1-res>=.500000000000)
            {
            ans=i;
                break;
            }


        }
        printf("Case %d: %d\n",cs,ans);


    }


    return 0;



}
