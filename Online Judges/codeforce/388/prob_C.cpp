#include<iostream>
#include<bits/stdc++.h>

using namespace std;


double dis(double x1,double y1,double x2,double y2)
{

    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{

    int n;
    cin>>n;
    string str;
    cin>>str;


    double x=0;
    double y=0;
    double pre=0;
    double x0=0;
    double y0=0;
    long long cnt=0;

    double prex=-1;
    double  prey=-1;

    for(int i=0; i<str.size() ; i++)
    {

        prex=x;
        prey=y;

       if(str[i]=='L')
        x-=1;
        if(str[i]=='R')
        x+=1;

        if(str[i]=='U')
        y+=1;

        if(str[i]=='D')
        y-=1;

        double d=dis(x,y,x0,y0);

        if(d>pre)
        {
            pre=d;
        }
        else
        {
            cnt+=1;
            pre=1;
            x0=prex;
            y0=prey;
        }


    }

    cout<<cnt+1<<endl;



}
