#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long arr[1000000];

int main()
{
    long long int n;
    string str;



    scanf("%lld",&n);
    cin>>str;
    for(int i=1;i<=str.size() ;i++)
    {
        scanf("%lld",&arr[i]);
    }

    bool flag=1;

    long long temp=1;
    long long temp2,temp1;

    for(int i=0 ;i<=10000000 ;i++)
    {


         if(temp<1 || temp>n)
        {
            cout<<"FINITE"<<endl;
            return 0;
        }

        if(str[temp-1]=='>')
            {

                temp1=arr[temp];
                temp+=arr[temp];

        if(temp<1 || temp>n)
        {
            cout<<"FINITE"<<endl;
            return 0;
        }

                flag=1;


            }
        else
            {
                if(flag==1 && arr[temp]==temp1)
                {

                     cout<<"INFINITE"<<endl;
                     return 0;
                }

                temp-=arr[temp];
                temp2=temp;


                flag=0;

            }



        if(temp<1 || temp>n)
        {
            cout<<"FINITE"<<endl;
            return 0;
        }
    }


     cout<<"INFINITE"<<endl;





    return 0;
}

