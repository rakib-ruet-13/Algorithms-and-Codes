#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pi acos(-1.000)
#define pb push_back

using namespace std;

string str;
vector<long long>vct;

long long mod=1000000007;

int arr[100100];



int main()
{
    long long n;

    cin>>str;

    long long res;
    res=1;

    for(int i=0; i<str.size(); i++)
    {
        unsigned long long int val;

        if(str[i]>='0' && str[i]<='9')
        {
            val=str[i]-'0';
        }
        else if(str[i]>='a' && str[i]<='z')
        {
            val=str[i]-'a'+36;
        }
        else if(str[i]>='A' && str[i]<='Z')
        {
            val=str[i]-'A'+10;
        }
        else if(str[i]=='-')
            val=62;
        else if(str[i]=='_')
            val=63;


        int cnt=0;


        unsigned long long a,b,c;
        for(unsigned long long int k=0;k<64;k++)
         for(unsigned long long int i=0;i<64;i++)
         {


            c=k&i;

            if(c==val)
            {
                cnt++;
            }

         }


        res*=cnt;
        res=res%mod;
    }

    cout<<res<<endl;



    return 0;
}

