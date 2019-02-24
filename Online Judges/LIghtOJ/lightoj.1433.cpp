#include<iostream>
#include<bits/stdc++.h>
#define pi acos(-1.0000)

using namespace std;

int main()
{

    int tc;
    scanf("%d",&tc);
    for(int cs=1 ; cs<= tc ; cs++)
    {
        double ox,oy,ax,ay,bx,by,a,c,theta;

        scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);



        a=sqrt( (ax-ox)*(ax-ox)+ (ay-oy)*(ay-oy));
        c=sqrt( (bx-ax)*(bx-ax) + ((by-ay)*(by-ay)));

        theta=acos((2*a*a-c*c)/(2*a*a));

         printf("Case %d: %.10lf\n",cs,theta*a);

    }


    return 0;
}
