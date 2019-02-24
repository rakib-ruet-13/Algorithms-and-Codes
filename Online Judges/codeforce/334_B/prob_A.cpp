#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{


     int m[5];
     int  w[5];
     int p[]={500,1000,1500,2000,2500};

    int h,u;

    for(int i=0;i<5;i++)
        cin>>m[i];
    for(int i=0;i<5;i++)
        cin>>w[i];
    cin>>h>>u;

    int sum=0;
    for(int i=0;i<5;i++)
    {
        int z=(p[i]/250)*(250-m[i])-50*w[i];
        int y=3*(p[i]/10);


        sum+=max(z,y);


    }

    sum=sum+h*100-u*50;
    cout<<sum<<endl;


}
