#include<iostream>
using namespace std;
int main()
{
    long int a,b,c,tc,i;
    cin>>tc;
   for(i=1;i<=tc;i++)
    {
        cin>>a>>b>>c;
        if((a>b && b>c)|| (c>b && b>a))
        cout<<"Case "<<i<<": "<<b;
        else if((b>a && c<a) || (c>a && a>b))
            cout<<"Case "<<i<<": "<<a;
        else
            cout<<"Case "<<i<<": "<<c;


            cout<<endl;

    }
    return 0;
}
