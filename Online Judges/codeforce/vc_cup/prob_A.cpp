#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;

    string str;
    cin>>str;

    long long cnt=0;
    long long ans=0;

    for(int i=1;i<str.size();i++)
    {
        if(str[i-1]=='L' && str[i]=='R')
            cnt++;
    }
    ans+=cnt;

    cnt=0;
      for(int i=1;i<str.size();i++)
    {
        if(str[i-1]=='R' && str[i]=='L')
            cnt++;
    }
    ans+=cnt;

     cnt=0;
      for(int i=1;i<str.size();i++)
    {
        if(str[i-1]=='U' && str[i]=='D')
            cnt++;
    }
    ans+=cnt;

     cnt=0;
      for(int i=1;i<str.size();i++)
    {
        if(str[i-1]=='D' && str[i]=='U')
            cnt++;
    }
    ans+=cnt;

    ans*=2;

    cout<<ans<<endl;
}
