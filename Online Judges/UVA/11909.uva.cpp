#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{

    long long int l,w,h,x;
    double ans,Pi,d;
    Pi=2.0*acos(0.0);

    while(cin>>l>>w>>h>>x)
    {
        d=l*tan(x*Pi/180);

        if(d>=(double)h)
        {
            ans=.5*tan(((Pi*(90-x))/180.0))*h*h*w;
        }
        else
        {
            ans=(l*w*h)-.5*tan((Pi*x)/180.0)*l*l*w;
        }
        cout<<fixed<<setprecision(3);
        cout<<ans<<" mL"<<endl;
    }
    return 0;
}
