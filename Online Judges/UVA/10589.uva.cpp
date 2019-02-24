#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    long long int n,a,m;
    double x,y;

    while(cin>>n>>a  && n!=0)
    {
        m=0;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;

            if( (x*x+y*y)<=a*a && ((x-a)*(x-a)+y*y)<=a*a && x*x+(y-a)*(y-a)<=a*a && (x-a)*(x-a)+(y-a)*(y-a)<=a*a)
                m++;

        }
        cout<<fixed<<setprecision(5);
        cout<<(double)((double)m*(double)a*(double)a)/(double)n<<endl;

    }

    return 0;


}
