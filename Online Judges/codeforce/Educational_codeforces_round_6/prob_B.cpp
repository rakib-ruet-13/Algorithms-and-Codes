#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long int sag_cnt(int n)
{
    long long res=0;
    while(n!=0)
    {
        int s=n%10;
        n=n/10;

        if(s==0 || s==6 || s==9)
        {
            res+=6;
        }
        else if(s==2 || s==5 || s==3)
        {
            res+=5;
        }
        else if(s==7)
            res+=3;
        else if(s==8)
            res+=7;
        else if(s==1)
            res+=2;
        else
            res+=4;
    }

    return res;
}


int main()
{


   long long int a,b;

   cin>>a>>b;

   long long sum=0;
   for(int i=a;i<=b;i++)
   {
       sum+=sag_cnt(i);
   }


   cout<<sum<<endl;





    return 0;
}
