#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b)
{
    return a>b;
}
int main()
{

    long long arr[100],num,i;

    for(i=0;i<100;i++)
    {
        num=rand();
        arr[i]=num;
    }
    sort(arr, arr+100,comp);

    for(i=0;i<100;i++)
        cout<<arr[i]<<" ";

}
