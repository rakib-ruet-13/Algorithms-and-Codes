#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    string s;
    int n,p,q,s;

    cin>>s;

    cin>>n>>p>>q;
    s=p+q;

    if(n%p==0)
    {
        for(int i=0;i<str.size();i++)
        {
            cout<<str[i];
            if(i!=0 && i%p==0)
                cout<<endl;
        }

    }
    else if(n%q==0)
    {
        for(int i=0;i<str.size();i++)
        {
            cout<<str[i];
            if(i!=0 && i%q==0)
                cout<<endl;
        }
    }
    else if(n%s==0)
    {
        bool flag=0;
        int cnt=0;


        for(int i=0;i<str.size();i++)
        {
            cout<<str[i];
            cnt++;

            if(cnt%p==0 && flag==0)
            {
                cout<<endl;
                flag=1;
            }
            if(cnt%q==0 && flag=1)


        }
    }
    else if((n%s)%p==0 !! (n%s)%q==0)
    {

    }



}
