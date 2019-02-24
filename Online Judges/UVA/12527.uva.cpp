#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool check(int i)
{
    int arr[10]={0};

    int num=i;

    while(num!=0)
    {
        arr[num%10]++;
        num=num/10;
    }

    int flag=0;
    for(i=0;i<10;i++)
    {
       if(arr[i]>1)
       {
           flag=1;
           break;
       }
    }

    if(flag==1)
        return false;
    else
        return true;
}

int main()
{

    int n,m,i,cnt;

    while(cin>>n>>m)
    {
        cnt=0;
        for(i=n;i<=m;i++)
        {
            if(check(i)==true)
                cnt++;

        }
        cout<<cnt<<endl;
    }
    return 0;


}

