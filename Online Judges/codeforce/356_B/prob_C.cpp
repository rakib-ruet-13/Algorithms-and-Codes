#include<iostream>
#include<bits/stdc++.h>


using namespace std;

//long long int arr[100100];
vector<long long>vct;


int arr[]={5,13,17,19, 23, 29, 31, 37, 41, 43, 7, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};


int main()
{
    string str;

    int cnt=0;
    bool flag=0;
    int i=0;int k=0;

    while(cin>>str)
    {
        ++k;

        if(str=="yes" && cnt==0)
        {
            cout<<2<<endl;
            cnt++;
        }
        else if(str=="yes" && cnt==1)
        {
            cout<<47<<endl;
            cnt++;
        }
        else
        {
            cout<<arr[i++]<<endl;
        }

        if(cnt==2)
        {
            cout<<"composite"<<endl;
            flag=1;
        }
    }

    for(int p=k+1 ; p<=20 ; p++)
    {
        cout<<arr[i++]<<endl;
    }

    if(flag!=1)
    cout<<"prime"<<endl;

}
