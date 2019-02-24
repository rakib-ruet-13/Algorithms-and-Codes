#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    vector<string>vct1,vct2;
    string str,str2;

    int cs;
    cin>>cs;

    for(int tc=1;tc<=cs;tc++)
    {

    cout<<"Case "<<tc<<":"<<endl;

    vct1.push_back("http://www.lightoj.com/");


    while(cin>>str && str!="QUIT")
    {
        if(str=="VISIT")
        {
            cin>>str2;
            cout<<str2<<endl;
            vct1.push_back(str2);
            vct2.clear();
        }
        if(str=="BACK")
        {
            if(vct1.size()==1)
                cout<<"Ignored"<<endl;
            else
            {
                str2=vct1.back();
                vct1.pop_back();
                cout<<vct1.back()<<endl;
                vct2.push_back(str2);
            }
        }
        if(str=="FORWARD")
        {
             if(vct2.size()==0)
                cout<<"Ignored"<<endl;
             else
             {
                str2=vct2.back();
                vct2.pop_back();
                cout<<str2<<endl;
                vct1.push_back(str2);
             }

        }

    }
    vct1.clear();
    vct2.clear();



    }



}
