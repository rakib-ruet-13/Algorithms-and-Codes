#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string arr[20000];

int main()
{

    //freopen("input.txt","r",stdin);

    int n;
    cin>>n;


    int flag=0;

    for(int i=1; i<=n ;i++)
    {
         cin>>arr[i];

        if((arr[i][0]=='O' && arr[i][1]=='O') && flag==0)
        {
            flag=1;
            arr[i][0]='+';
            arr[i][1]='+';
        }


        if((arr[i][3]=='O' && arr[i][4]=='O') && flag==0)
        {
            flag=1;
            arr[i][3]='+';
            arr[i][4]='+';
        }


    }

    if(flag==0)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=1; i<=n ;i++)
            cout<<arr[i]<<endl;
    }



    return 0;
}
