#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long int num,ans;

    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>num;
        ans=((((num*567)/9)+7492)*235/47)-498;
        if(ans<0)
            ans=ans*(-1);
        ans=ans/10;

        cout<<ans%10<<endl;

    }
        return 0;
}
