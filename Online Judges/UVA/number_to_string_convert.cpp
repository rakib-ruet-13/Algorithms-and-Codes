#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctype.h>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


string convert_str(long long int n)
{
    //cout<<"in"<<endl;
    vector<char>vct;
    char str[20];
    int k,l;
    k=0;
    do
    {
        vct.push_back(((n%10)+48));
        n=n/10;
    }
    while(n!=0);

    reverse(vct.begin(),vct.end());

    l=vct.size();
    for(int l1=0;l1<l;l1++)
    {
        str[k++]=vct[l1];
    }
    str[k]='\0';
    vct.clear();

    return str;

}
int main()
{
    long long int num,i;
    string str,st1,st[501];
    st[1]=convert_str(1);
    st[0]=convert_str(1);
        st1=convert_str(1);
       while(cin>>i)
        {

            str=convert_str(i);
            cout<<str<<endl;

        }


    return 0;


}






