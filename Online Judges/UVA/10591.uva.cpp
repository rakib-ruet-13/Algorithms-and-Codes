#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long int happy_sum(long int num);

long int arr[10000000];
vector<long int>a;

int main()
{
    long int num,i,new_num,flag,cs=0,tc,temp;

    for(i=0;i<10000000;i++)
    {
        arr[i]=-9999999;
    }
     cin>>tc;

    while(tc--)
    {
        cin>>num;
        temp=num;
        flag=1;
        a.push_back(num);
        while(num!=1)
        {
            if(num<10000000)
            if(arr[num]==1)
            {
                break;
            }
            if(num<10000000)
            if(arr[num]==0)
            {
                flag=0;
                break;
            }

            num=happy_sum(num);
            a.push_back(num);
            int l=a.size();
            for(int i=0;i<l-1;i++)
            {

                if(num<10000000)
                    if(arr[num]==0 )
                    {
                        flag=0;
                        break;
                    }
                if(a[i]==num)
                {
                    if(num<10000000)
                    if(arr[num]==0 )
                    {
                        flag=0;
                        break;
                    }
                    for(int j=0;j<l-1;j++)
                    {
                        if(a[j]<10000000)
                        arr[a[j]]=0;
                    }
                    flag=0;
                    break;

                }
            }
            if(flag==0)
                break;

        }
        if(flag==0)
            cout<<"Case #"<<++cs<<": "<<temp<<" is an Unhappy number."<<endl;
        else
        {
            for(i=0;i<a.size();i++)
            {
                if(a[i]<10000000)
                arr[a[i]]=1;
            }

            cout<<"Case #"<<++cs<<": "<<temp<<" is a Happy number."<<endl;
        }
        a.clear();

    }
    return 0;
}

long int happy_sum(long int num)
{
    int i,sum=0;
    do
    {
        sum+=(num%10)*(num%10);
        num=num/10;

    }
    while(num!=0);

    //cout<<sum<<endl;

    return sum;
}
