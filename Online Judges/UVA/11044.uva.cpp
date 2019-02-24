#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n,m,tc,i,j;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        i=ceil((float)(n-2)/3);
        j=ceil((float)(m-2)/3);
        cout<<i*j<<endl;

    }
    return 0;
}
