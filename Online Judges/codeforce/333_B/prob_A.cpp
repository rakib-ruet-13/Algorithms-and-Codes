#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 vector<int>arr;

long long int power(int base,int p)
{
    long long sum=1;
    if(p==0)
        return 1;
    else
    {
        for(int i=1;i<=p;i++)
        {
            sum*=base;
        }
    }
    return sum;


}

long long int base_con(long long int base,long long int n)
{

    long long int sum=0;
    int cnt=0;
    for(long long int i=n-1;i>=0;i--)
    {
        sum+=arr[cnt++]*power(base,i);

    }

    return sum;
}

int main()
{

    long long int n1,b1,n2,b2,num1,num2;


    cin>>n1>>b1;
    for(int i=0;i<n1;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    num1=base_con(b1,n1);
    arr.clear();

    cin>>n2>>b2;
    for(int i=0;i<n2;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    num2=base_con(b2,n2);

    if(num1==num2)
        cout<<"="<<endl;
    else if(num1<num2)
        cout<<"<"<<endl;
    else
        cout<<">"<<endl;

}
