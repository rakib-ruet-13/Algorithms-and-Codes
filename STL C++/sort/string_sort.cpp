#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b)
{
    int mini=min(a.size(),b.size());
    {
        for(int i=0;i<mini;i++)
        {
            if(a[i]!=b[i])
            if((a[i]<='a' && a[i]<='z') && (b[i]<='a' && b[i]<='z'))

                    return a[i]<b[i];
            else
            {
                if((a[i]<='0' && a[i]<='9') && (b[i]<='a' && b[i]<='z'))
                  return a[i]>b[i];

                  if((a[i]<='a' && a[i]<='z') && (b[i]<='0' && b[i]<='9'))
                    return a[i]>b[i];

                    if((a[i]<='0' && a[i]<='9') && (b[i]<='0' && b[i]<='9'))
                      return a[i]<b[i];
            }
        }
    }
     return a.size()< b.size();
}

int main()
{
    string str[5];

    for(int i=0;i<5;i++)
    {
        cin>>str[i];
    }


    sort(str,str+5,comp);

     for(int i=0;i<5;i++)
    {
        cout<<str[i]<<endl;
    }


}

