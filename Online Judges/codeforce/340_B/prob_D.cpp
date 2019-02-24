#include<iostream>
#include<bits/stdc++.h>


using namespace std;



int main()
{
    long long int x[4],y[4];


    for(int i=1;i<=3;i++)
        cin>>x[i]>>y[i];


    if((x[1]==x[2] && x[1]==x[3]) ||(y[1]==y[2] && y[2]==y[3] ))
    {
        cout<<1<<endl;
    }

    else if(x[1]==x[2] && (y[3]==y[1] || y[3]==y[2])  && ((y[3]>y[1] && y[3]>y[2] )|| (y[3]<y[1] && y[3]<y[2] )))
      cout<<2<<endl;
    else if(x[2]==x[3] && (y[2]==y[1] || y[3]==y[1])   && ((y[1]>y[2] && y[1]>y[3]) || (y[1]<y[2] && y[1]<y[3] ) ))
       cout<<2<<endl;
     else if(x[1]==x[3] && (y[1]==y[2] || y[3]==y[2])  && ( (y[2]>y[1] && y[2]>y[3]) || (y[2]<y[1] && y[2]<y[3] )))
        cout<<2<<endl;
     else if( (y[1]==y[2]) && (x[1]==x[3] || x[2]==x[3])  && ((x[3]>[1] && x[3]>x[2] )|| (x[3]<x[1] && [3]<[2] ) ))
        cout<<2<<endl;
      else if( (y[2]==y[3]) && (x[2]==x[1] || x[3]==x[1])  &&  ((x[1]>[2] && x[1]>x[3]) || (x[1]<x[2] && x[1]<[3] )))
         cout<<2<<endl;
       else if( (y[1]==y[3]) && (x[1]==x[2] || x[3]==x[2]) && ((x[2]>[1] && x[2]>[3]) || (x[2]<x[1] && x[2]<[3] )))

         cout<<2<<endl;
      else
        cout<<3<<endl;



}
