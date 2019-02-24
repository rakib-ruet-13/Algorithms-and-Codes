#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int arr[100];

int main()
{
    long long n,res;

    scanf("%lld",&n);

    int pre=0;

    bool flag=0;

    int val;


    memset(arr,0,sizeof(arr));
    for(int i=0; i<n ;i++)
    {
        scanf("%d",&val);
        arr[val]=1;

    }


    int cnt=0;

    res=0;
    for(int i=1; i<=90 ;i++)
    {
        if(arr[i]==0)
            cnt++;

        if(arr[i]==1)
            cnt=0;
        res++;
        if(cnt==15)
            break;


    }

    printf("%lld\n",res);



    return 0;


}
