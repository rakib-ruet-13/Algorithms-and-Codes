#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str1,str2;
    queue<char>st,q2;

    getline(cin,str1);

    getline(cin,str2);

    //int s=str2.size();

    int cnt=0;

    for(int i=0;i<str1.size();i++)
    {

        if(str1[i]==str2[0])
        {
            bool flag=1;
            bool flag2=1;

            for(int k=0;k<str2.size();k++)
            {
                if(i+k<str1.size())
                  if(str1[i+k]!=str2[k])
                  {
                     flag=0;
                     flag2=0;
                     break;
                  }
                   else;
                else
                {
                    flag=0;
                    flag2=0;
                    break;
                }

            }

            if(flag==1)
                cnt++;


        }
    }

    cout<<cnt<<endl;



}


