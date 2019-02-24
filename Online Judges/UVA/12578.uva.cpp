#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#define Pi 2*acos(0.0)

using namespace std;
int main()
{
    long long int tc,l;
    double w,r,area1,area2;
    cin>>tc;
    while(tc--)
    {
        cin>>l;
        w=(double)l*6/10;

        r=(double)l/5;

        area1=Pi*r*r;
        area2=w*(double)l-area1;

        printf("%.2f %.2f\n",area1,area2);

    }

    return 0;

}
