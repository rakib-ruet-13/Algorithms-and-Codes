#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int tc,i;
    double d,v,u,s1,s2;
    cin>>tc;
    for(i=1;i<=tc;i++)
    {
        cin>>d>>v>>u;
        if(u=0||v>=u)
            cout<<"can't determine"<<endl;
        else
        {
            s1=1.0*d/u*1.0;
            s2=d/((u*u-v*v)/(u*u-v*v));
            cout<<s1<<s2;
            printf("Case %d: %.3lf\n",i,s2-s1);
        }
    }

    return 0;


}
