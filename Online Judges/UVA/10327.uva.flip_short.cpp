#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long int arr[100000];
    int num,cnt,i,j,temp;
    while(scanf("%d",&num)==1)
    {
        cnt=0;
        for(i=0;i<num;i++)
            cin>>arr[i];

        for(i=0;i<num-1;i++)
            for(j=0;j<num-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                cnt++;
            }
        }
        cout<<"Minimum exchange operations : "<<cnt<<endl;
    }

    return 0;
}
