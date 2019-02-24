#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    double ans,n,m;
    long int a,b,c,d;
    while(cin>>a>>b>>n)
    {
        m=1/(b*n);
        c=(a*m+1);
        d=b*m;
        cout<<c<<d<<endl;

    }
    return 0;

}
