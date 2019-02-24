#include<iostream>
#include<bits/stdc++.h>
using namespace std;



long long int power(long long int base,long long int p)
{
    long long int ans=1;
    if(p==0)
        return 1;
    else
    {
        for(int i=1;i<=p;i++)
        {
           ans=ans*base;
        }
    }
    return ans;
}


int main()
{

    long long int n,ans,tc,sum;

    cin>>tc;

    while(tc--)
    {
        cin>>n;

        ans=(n*(n+1))/2;

        int i=0;
        sum=0;
        while(power(2,i)<=n)
        {
            sum+=power(2,i);
            i++;
        }

        cout<<ans-2*sum<<endl;


    }


}
