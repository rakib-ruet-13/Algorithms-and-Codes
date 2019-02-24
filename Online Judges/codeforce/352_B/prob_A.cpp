#include<iostream>
#include<bits/stdc++.h>

using namespace std;




string  con(int n)
    {
        string str;
        str.clear();

        while(n!=0)
        {
            str+=(char(n%10+'0'));
            n=n/10;
        }

        reverse(str.begin(), str.end());

        return str;
    }
int main()
{

    long long n;
    string str;




    for(int i=1; i<1000 ;i++)
    {
        str+=con(i);

    }

    cin>>n;

    cout<<str[n-1]<<endl;




    return 0;

}
