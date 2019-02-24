#include<iostream>
using namespace std;
int main()
{
    long long int n,ans;
    while(cin>>n && n)
    {
            ans=n*(n+1)*(2*n+1)/6;
            cout<<ans<<endl;

    }
    return 0;
}
