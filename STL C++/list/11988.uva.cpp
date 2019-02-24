#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    list<string>l;
    list<string>:: iterator it;
    string str,str2;

    while(cin>>str)
    {
        int s=str.size();
        bool flag=true;
        for(int i=0;i<s;i++)
        {
            if(str[i]!='[' && str[i]!=']')
               str2+=str[i];

            if(str[i]=='[')
                {

                    if(flag==true)
                    l.push_back(str2);
                    else
                    l.push_front(str2);

                    str2.clear();
                    flag=false;

                }
            if(str[i]==']')
                {
                    if(flag==false)
                    l.push_front(str2);
                    else
                        l.push_back(str2);

                    str2.clear();
                    flag=true;
                }


        }
         if(!str2.empty())
         {
             if(flag==false)
                l.push_front(str2);
             else
                 l.push_back(str2);
         }

            str2.clear();

        for(it=l.begin();it!=l.end();it++)
        {
            cout<<*it;
        }
        cout<<endl;

        l.clear();

    }
}
