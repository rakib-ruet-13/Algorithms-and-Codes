#include<iostream>
using namespace std;

long long int temp;

long long mod(long long int n,long long int p,long long int m)
{
    if(p==0)
        return 1;
    else if(p%2==1)
        return (((n%m)*mod(n,p-1,m)%m)%m);
    else
        temp=(mod(n,p/2,m)%m)%m;

        return ((temp*temp)%m)%m;
}

int main()
{
    long long n,a,b,c;

    while(cin>>n && n!=0)
    {
        while(n--)
        {
             cin>>a>>b>>c;

             cout<<mod(a,b,c)<<endl;
        }
    }
}



