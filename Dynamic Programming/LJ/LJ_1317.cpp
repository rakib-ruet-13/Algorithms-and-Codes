#include<iostream>
#include<bits/stdc++.h>

using namespace std;




int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ; cs++)
    {
       double a,b,c,d;

       scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

       printf("Case %d: %.10f\n",cs,a*c*d);

    }


    return 0;
}

