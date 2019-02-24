#include<iostream>
#include<bits/stdc++.h>
#define pi (2*acos(0.0))
using namespace std;

int main()
{

    int tc;
    scanf("%d",&tc);
    for(int cs=1; cs<= tc ; cs++)
    {
        double r1,r2,r3,a,b,c,s,ar1,sum;

        scanf("%lf %lf %lf",&r1,&r2,&r3);

        a=r1+r2;
        b=r1+r3;
        c=r2+r3;

        s=(a+b+c)/2.000;

        ar1= fabs(sqrt(s*(s-a)*(s-b)*(s-c)));

        ar1-= (r1*r1*acos((a*a+b*b-c*c)/(2*a*b)))/2.000;
         ar1-= (r2*r2*acos((c*c+a*a-b*b)/(2*a*c)))/2.000;
          ar1-= (r3*r3*acos((c*c+b*b-a*a)/(2*c*b)))/2.000;


          printf("Case %d: %.10lf\n",cs,ar1);



    }





    return 0;
}
