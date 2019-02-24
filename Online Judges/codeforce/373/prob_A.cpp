#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

int arr[101];

int main()
{

    int n;
    cin>>n;

    for(int i=1; i<=n ;i++)
        cin>>arr[i];

    if(arr[n]==15)
        {
            cout<<"DOWN"<<endl;
            return 0;}
        if(arr[n]==0)
        {
            cout<<"UP"<<endl;
            return 0;
        }

    if(n==1)
        {
            cout<<-1<<endl;
            return 0;
        }
    if(arr[n-1]< arr[n] && arr[n]!=15)
    {
        cout<<"UP"<<endl;
    }
    else if(arr[n-1]< arr[n] && arr[n]==15)
    {
        cout<<"DOWN"<<endl;
    }
    else if(arr[n]==0)
    {
        cout<<"UP"<<endl;
    }
    else
    {
        cout<<"DOWN"<<endl;
    }




    return 0;
}

