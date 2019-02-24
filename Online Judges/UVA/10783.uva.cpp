#include<iostream>
using namespace std;
int main()
{
    int tc,ll,ul,sum,i,j=1;
    cin>>tc;
    while(j<=tc)
    {
        sum=0;
        cin>>ll>>ul;
        if(ll%2==0)
            ll=ll+1;
        while(i<=ul)
        {
            i=ll;
            sum=sum+i;
                i=i+2;
        }
        cout<<"Case "<<j<<": "<<sum<<endl;
        j++;


    }
    return 0;
}
