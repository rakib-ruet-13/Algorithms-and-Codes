#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int Case,cnt=1;
    double a,b,c,d;

    while(cin>>Case && Case!=0)
    {
        cin>>a>>b>>c;
        cout<<"Case "<<cnt++<<": ";
        if(Case==1)
        {
            printf("%.3lf %.3lf\n",(a+b)/2*c,(b-a)/c);
        }
        else if(Case==2)
        {
            printf("%.3lf %.3lf\n",(b*b-a*a)/2/c,(b-a)/c);
        }
        else if(Case==3)
        {
            d=sqrt(a*a+2*b*c);
            printf("%.3lf %.3lf\n",d,(d-a)/b);
        }
        else
        {
            d=sqrt(a*a-2*b*c);
            printf("%.3lf %.3lf\n",d,(a-d)/b);
        }
    }
    return 0;
}
