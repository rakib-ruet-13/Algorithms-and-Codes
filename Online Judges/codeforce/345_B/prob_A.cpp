#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long a,b;

    cin>>a>>b;

    long long cnt=0;
     do
    {
        if(a==1 && b==1)
            break;

         if(a>=b)
            {

                a-=2;


                 b+=1;
            }
        else
            {
                b-=2;

                a+=1;
            }



          cnt++;


    }
     while((a>=1 && b>=2) || (a>=2 && b>=1));



    cout<<cnt<<endl;


    return 0;


}
