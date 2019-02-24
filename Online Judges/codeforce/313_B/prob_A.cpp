#include<iostream>
using namespace std;

int main()
{
    long int n,ans,num;
    cin>>n;
    ans=1;
    while(n--)
    {
        cin>>num;
        if(num==1)
            ans=-1;
    }
    cout<<ans<<endl;


    return 0;
}
