#include<iostream>
using namespace std;

int main()
{
    long long int tc,n,cs=0,ans;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        ans=n*(n-1);


        if(ans==0)
           {
               cout<<"Case "<<++cs<<": "<<0<<endl;

           }
        else if(ans%4==0)
        {
            cout<<"Case "<<++cs<<": "<<ans/4<<endl;
        }

        else
            cout<<"Case "<<++cs<<": "<<ans/2<<"/"<<2<<endl;
    }
    return 0;
}

