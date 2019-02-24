#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long power(long long n,long long base)
{

    long long ans=1;

    if(base==0)
        return 1;

    for(int i=1;i<=base;i++)
    {
        ans*=n;
        if(ans>1000000000000000000)
            return 1111111111111111111;
    }

    return ans;

}

int main()
{
    long long l,r,n;

    cin>>l>>r>>n;

        int cnt=0;
        for(long long i=0; ;i++)
        {
            long long num=power(n,i);
            long long pre=num;

            if(num>r)
                break;

                if(n>1000000 && i>2)
                    break;

                    if(pre<num  || num>1000000000000000000)
                        break;


            else if(num>=l)
                {
                   if(cnt==0)
                    cout<<num;
                   else
                    cout<<" "<<num;


                   cnt++;
                }
        }

        if(cnt==0)
            cout<<"-1"<<endl;
        else
            cout<<endl;




    return 0;
}
