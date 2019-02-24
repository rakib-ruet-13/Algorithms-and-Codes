#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int c,i,n;
    double a[1000];
    cin>>c;
    while(c--)
    {  double avg=0;
        double sum=0;
        int cnt=0;
         cin>>n;
        for( i=0;i<n;i++)
        {
            cin>>a[i];
            sum=sum+a[i];
        }
        avg=sum/n;
          for( i=0;i<n;i++)
            if(a[i]<avg)
                cnt++;
            printf("%.3lf%%\n",(float)(n-cnt)/(float)n*100);
    }

    return 0;
}

