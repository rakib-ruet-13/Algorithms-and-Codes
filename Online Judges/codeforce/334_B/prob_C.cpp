#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    getchar();
    string str;

    getline(cin,str);

    int l=str.size();

    int flag=1;
    int cnt1=0;
    char ch='1';
    for(int i=0;i<l;i++)
    {
        if(i==0)
        {
            ch=str[i];
            cnt1++;
        }
        if(str[i]!=ch)
         {
             ch=str[i];
             cnt1++;
         }

    }

    cout<<cnt1<<endl;

    int k=0;

    int mx=-9999;
    for(int i=0;i<l;i++)
    {
       k=i;
       int cnt=1;
       while(str[k]==str[k+1] && k+1<l)
       {
           cnt++;
           k++;
       }

       mx=max(mx,cnt);
       i=k;
    }
    cout<<mx<<endl;
    if(mx<=2)
        mx=0;


     if(mx%2==0)
       mx=mx/2;
    else
        mx=mx/2+1;




    cout<<cnt1+mx<<endl;



}
