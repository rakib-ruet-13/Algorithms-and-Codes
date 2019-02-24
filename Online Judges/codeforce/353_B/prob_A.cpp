#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int a,b,c;

    cin>>a>>b>>c;

    if(c==0)
    {
        if(a==b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else if(c>0)
    {
        if(b>=a)
        {
            if(abs(b-a)%abs(c)==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        cout<<"NO"<<endl;

    }
    else
    {
        if(a>=b)
        {

            if(abs(b-a)%abs(c)==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}
