#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    long long n;
    long long a,b,c;

    cin>>n;
    a=1234567;
    b=123456;
    c=1234;

    bool flag=true;

    for(int i=0;i<=n/1234567 && flag ;i++)
    {
        for(int j=0; j<=n/123456 && flag ;j++)
        {

                long long res=i*a+j*b;

                if((n-res)>=0 && (n-res)%1234==0)
                 {

                    flag=false;
                 }

        }
    }

    if(!flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}
