#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
    long long int arr[3],a,b;

        while(  scanf("%lld %lld %lld",&arr[0],&arr[1],&arr[2])==3 && arr[0]!=0)
        {
            sort(arr,arr+3);

            a=arr[2]*arr[2];
            b=arr[1]*arr[1]+arr[0]*arr[0];
            if(a==b)
                cout<<"right"<<endl;
            else
                cout<<"wrong"<<endl;
        }

}
