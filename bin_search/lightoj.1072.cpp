#include<iostream>
#include<bits/stdc++.h>

using namespace std;



double fun(double r,double theta)
{
    return r+(r/(sin(theta)));

}

double bin_search(double R,double n)
{

    double theta=2*acos(-1.00000)/(n*2.000);

   double up=1000000.00000000;
   double ll=0.000000;
   double mid;

  // cout<<1111<<endl;

   mid=(up+ll)/2.00000000;

   while( up>ll)
   {



       //cout<<ll<<"   "<<mid<<" "<<up<<" "<<fun(mid,theta)<<endl;

       if(fun(mid,theta) <= R)
        ll=mid;
        else
        up=mid;

      mid=(ll+up)/2.0000;

        if(fabs(up-ll)<.000000001)
            break;
   }


    return mid;
}

int main()
{



    int tc;
    scanf("%d",&tc);

    //cout<<fun(1.333333, acos(-1.0000)/12)<<endl;

    //cout<<sin( 2*acos(-1.000)/12)<<endl;


    for(int cs=1 ;cs<=tc ;cs++)
    {
        double R,n;
        scanf("%lf %lf",&R,&n);

        printf("Case %d: %.10lf\n",cs,bin_search(R,n));


    }


}
