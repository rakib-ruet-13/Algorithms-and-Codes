#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;

long long int a[500000];
int main()
{
    long long int n,w,Min1,Min2,l;
    double x;

    while(cin>>n)
    {
        cin>>w;
        l=2*n;
        for(int i=0;i<l;i++)
           cin>>a[i];

         sort(a,a+(2*n));
          Min1=a[0];
          Min2=a[n];

        x=(double)w/(double)(n+2*n);

       if((Min1*2)<= Min2)
        {
            if(x<double(Min1))
                printf("%.10f\n",(double)n*3.0*x);
            else
                printf("%.10f\n",(double)n*3.0*Min1);


        }
        else
        {
            if((x*2) < double(Min2))
                printf("%.10f\n",(double)n*3.0*x);
            else
                printf("%.10f\n",(double)n*3.0*(Min2/2.0));
        }



    }
}
