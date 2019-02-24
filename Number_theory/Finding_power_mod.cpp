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

    while(1)
   {




    long long a,b,c;
    cin>>a>>b;
    long long n;
    n=mod(a,b*a,1000000007);
    cout<<n;

   }
}


