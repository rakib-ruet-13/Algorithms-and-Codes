#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    string str,st;

    int l,r,m,k,strt,fin,sft;

    getline(cin,str);

    cin>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>l>>r>>k;

        sft=(k%(r-l+1));


        for(int i=0;i<l-1;i++)
        st.push_back(str[i]);

        for(int i=r-sft;i<r;i++)
        {
            st.push_back(str[i]);

        }

        for(int i=l-1;i<r-sft;i++)
            st.push_back(str[i]);

         for(int i=r;i<str.size();i++)
            st.push_back(str[i]);


        //cout<<str<<endl;
        //cout<<st<<endl;

         str=st;
         st.clear();





    }

    cout<<str<<endl;



}
