#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;

int main()
{
    int tc,Min,Hour;
    string str;
    cin>>tc;
    getchar();
    while(tc--)
    {
        getline(cin,str);
        Min=((str[3]-48)*10+str[4]-48);
        Hour=((str[0]-48)*10+str[1]-48);

        Min=60-Min;
        if(Min==60)
            Hour=12-Hour;
        else if(Hour==12)
            Hour=11;
        else
            Hour=11-Hour;


        if(Hour==0)
         cout<<"12:";
        else if(Hour>=10)
        {
          cout<<Hour<<":";
        }
        else
            cout<<"0"<<Hour<<":";


        if(Min==60)
            cout<<"00";
        else if(Min<10)
            cout<<"0"<<Min;
        else
            cout<<Min;

        cout<<endl;

        str.clear();




    }
    return 0;
}
