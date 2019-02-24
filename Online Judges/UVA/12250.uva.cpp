#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tc,cs=0;
    string st[6],str;
    st[0]="HELLO";
    st[1]="HOLA";
    st[2]="HALLO";
    st[3]="BONJOUR";
    st[4]="CIAO";
    st[5]="ZDRAVSTVUJTE";

    while(cin>>str && !(str[0]=='#' && str.size()==1))
    {
        cout<<"Case "<<++cs<<": ";

        if(st[0]==str)
            cout<<"ENGLISH"<<endl;
        else if(st[1]==str)
            cout<<"SPANISH"<<endl;
        else if(st[2]==str)
            cout<<"GERMAN"<<endl;
        else if(st[3]==str)
            cout<<"FRENCH"<<endl;
        else if(st[4]==str)
            cout<<"ITALIAN"<<endl;
        else if(st[5]==str)
            cout<<"RUSSIAN"<<endl;
        else
            cout<<"UNKNOWN"<<endl;


    }

    return 0;




}
