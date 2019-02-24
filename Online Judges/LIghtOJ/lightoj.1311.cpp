#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int tc;

    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        double v1,v2,v3,a1,a2,d,t;
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);

        d= v1*v1/(double)2/a1 + v2*v2/(double)2/a2;
        t=max(v1/a1,v2/a2);

        printf("Case %d: %.10lf %.10lf\n",cs,d,v3*t);
    }





    return 0;
}
