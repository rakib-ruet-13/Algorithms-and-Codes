#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long power(long long base,int p)
{
    if(p==0)
        return 1;

        long long ans=1;

    for(int i=1;i<=p;i++)
    {
        ans*=base;
    }

    return ans;
}

int main()
{
    long long n;

    cin>>n;

    bool flag=0;

    while(n!=0)
    {
        long long k=n;


            int cnt=0;

            while(k)
            {
                k=k/2;
                cnt++;
            }

            long long temp=power(2,cnt-1);

            //cout<<"temp "<<temp<<" "<<n<<endl;

            if(temp==n)
            {
                if(flag==0)
                cout<<cnt<<endl;
                else
                {
                    flag=1;
                    cout<<" "<<cnt<<endl;
                }

                return 0;
            }
            else
            {
                if(flag==0)
                    {
                        flag=1;
                        cout<<cnt;
                    }
                else
                {
                    cout<<" "<<cnt;
                }


            }
           n=n-temp;

    }
    cout<<endl;




    return 0;


}

