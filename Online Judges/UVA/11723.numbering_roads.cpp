#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int i,r,n,cnt,j=1;
    while(scanf("%d %d",&r,&n)==2 && (r!=0 && n!=0 ))
    {
        cnt=0;
        if(n*27<r)
            cout<<"Case "<<j<<": "<<"impossible"<<endl;

        else
          {
               i=r-n;
            while(i>0)
            {
             i=i-26;
             cnt++;
            }
            cout<<"Case "<<j<<": "<<cnt<<endl;}

            j++;

    }
}
