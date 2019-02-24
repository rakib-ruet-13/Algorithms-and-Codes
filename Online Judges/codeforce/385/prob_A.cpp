#include<iostream>
#include<bits/stdc++.h>

using namespace std;


map<string,int>mymap;

int main()
{


    string str,str1;
    cin>>str;

    str1=str;
    str1+=str;

    //cout<<str1<<endl;


    string st;


    for(int i=0; i<str.size() ;i++)
    {


        for(int j=i; j< i+ str.size() ; j++)
        {
            st+=str1[j];
        }

        mymap[st]++;
         st.clear();

    }

    cout<<mymap.size()<<endl;

}
