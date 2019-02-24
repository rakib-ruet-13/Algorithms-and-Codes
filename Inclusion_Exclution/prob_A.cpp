#include<iostream>
#include<bits/stdc++.h>

using namespace std;

map<string,int>mymap;

int main()
{

    int n;
    cin>>n;

    string str;


    for(int i=0; i<n ; i++)
    {
        cin>>str;

        if(mymap[str]==3)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

        mymap[str]=3;

    }


    return 0;
}
