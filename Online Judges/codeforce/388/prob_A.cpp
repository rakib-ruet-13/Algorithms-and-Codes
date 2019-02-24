#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long l,m,n;
    cin>>l>>m>>n;

    long long int p=ceil((double)n/(double)(2*m));
    long long int q=n%(2*m);

    if(q==0)
        q=2*m;

    char ch;

    if(q%2==1)
        ch='L';
    else
        ch='R';

    q=ceil((double)q/2.000);


    cout<<p<<" "<<q<<" "<<ch<<endl;





}
