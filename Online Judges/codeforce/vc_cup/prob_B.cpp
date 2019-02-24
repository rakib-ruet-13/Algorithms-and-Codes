#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    char ch;
    int b,r,g;

    cin>>n;
    b=r=g=0;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        if(ch=='B')
            b++;
        else if(ch=='G')
            g++;
        else
            r++;
    }

    if((1<=r && 1<=g) || ((r==0 && g==0 && b) || (r>1 && b) || (g>1 && b)) )
    {
        cout<<"B";
    }
    if((1<=r && 1<=b) || ((r==0 && b==0 && g) || (r>1 && g) || (b>1 && g)))
   {
       cout<<"G";
   }


     if((1<=g && 1<=b) || ((g==0 && b==0 && r) || (g>1 && r) || (b>1 && r)))
   {
       cout<<"R";
   }

   cout<<endl;



}
