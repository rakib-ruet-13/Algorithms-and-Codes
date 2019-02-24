#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

long long int GCD(long long a,long long b)
{
    if(a%b==0)
        return b;
    GCD(b,a%b);
}

int main()
{
    long long int num1,num2;
    while(1)
    {
        cin>>num1>>num2;

        cout<<GCD(num1,num2)<<endl;
    }


}
