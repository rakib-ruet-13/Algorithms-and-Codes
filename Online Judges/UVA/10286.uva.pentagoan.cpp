#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define Pi 2*acos(0.0)
using namespace std;

int main()
{
    double r;
    while(cin>>r)
    {
        printf("%.10f\n",sin(108*Pi/180)/sin(63*Pi/180)*r);
    }

return 0;
}
