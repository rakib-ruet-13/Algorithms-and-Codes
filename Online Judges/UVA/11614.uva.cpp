#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    long long int tc,num,ans;
    double s;
    cin>>tc;
    while(tc--)
    {
        cin>>num;
        s=1+8*num;
        s=(sqrt(s)-1)/2;
        ans=floor(s);
        cout<<ans<<endl;

    }
    return 0;
}
