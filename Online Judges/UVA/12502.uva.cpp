#include<iostream>
using namespace std;
int main()
{
    int a,b,c,tc,ans;
    cin>>tc;
    while(tc--)
    {
        cin>>a>>b>>c;
        ans=((2*a-b)*c)/(a+b);
        if(ans<0)
            cout<<0<<endl;
        else
        cout<<ans<<endl;

    }
    return 0;
}
