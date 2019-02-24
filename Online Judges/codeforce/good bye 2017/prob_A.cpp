#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{


    string str;
    cin>>str;

    int cnt1=0;
    int cnt2=0;

    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            cnt1++;

         if((str[i]=='1' || str[i]=='3' || str[i]=='5' || str[i]=='7' || str[i]=='9'))
            cnt2++;
    }
        cout<<cnt1+cnt2<<endl;



    return 0;
}
