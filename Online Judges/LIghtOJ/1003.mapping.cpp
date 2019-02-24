#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    string str1,str2;
    map<string ,string>mymap;

    int tc,m;
    cin>>tc;
    for(int cs=1;cs<=tc;cs++)
    {

        cin>>m;

        int flag=1;
        for(int i=0;i<m;i++)
        {
            cin>>str1>>str2;

            mymap[str1]=str2;


                if(mymap[str2]==str1)
                    flag=0;


        }

        if(flag==0)
        {
            cout<<"Case "<<cs<<": "<<"No"<<endl;

        }
        else
             cout<<"Case "<<cs<<": "<<"Yes"<<endl;

        mymap.clear();


    }


    return 0;
}
