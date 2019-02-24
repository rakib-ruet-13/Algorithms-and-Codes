#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int mod(long long int base,long long int p,long long int m)
{

    if(p==0)
        return 1;
    else if(p%2==0)
    {
        long long ret=(mod(base,p/2,m));
        return (ret%m)*(ret%m);
    }

    else
        return (base*mod(base,p-1,m))%m;

}


int main()
{
    long long int n;

    while(cin>>n)
    {
        long long int cnt=0;
        long long int sum=0;
        for(int i=0; ;i++)
        {
            sum=(sum+(mod(2,i,n)*mod(5,i,n))%n)%n;
            cnt++;
            if(sum==0)
                break;
        }

        cout<<cnt<<endl;
    }
}
