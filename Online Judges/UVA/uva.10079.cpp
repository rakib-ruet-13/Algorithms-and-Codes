#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    while(0<=n)
    {
        if(n==0)
        {
            n=1;
            cout<<n<<endl;}
        else
            cout<<n*(n+1)/2+1<<endl;
            cin>>n;
    }
    return 0;
}

