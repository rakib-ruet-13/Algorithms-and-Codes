#include<iostream>
#include<bits/stdc++.h>
#define pi acos(-1.0000)
using namespace std;


int main()
{

    int tc;

    scanf("%d",&tc);

    double r1,r2,h,p,R1,R2,res;

    for(int cs=1 ; cs<=tc ; cs++)
    {
        cin>>r1>>r2>>h>>p;

        R1=r2;
        R2=r2+(r1-r2)*(p/h);
        //cout<<pi<<endl;
        //cout<<r1<<" "<<r2<<endl;
        //cout<<R1<<" "<<R2<<endl;

        res=((double)1/(double)3)*pi*p*(R1*R1+R1*R2+R2*R2);

        //cout<<res<<endl;

        printf("Case %d: %.10lf\n",cs,res);




    }





    return 0;
}
