#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string str1,str2,str3;

string st;

int lcs(int i,int j,int k)
{
    if(i>=str1.size() || j>=str2.size() || k>=str3.size())
        return 0;

    if(str1[i]==str2[j] && str2[j]==str3[k])
    {
        return 1+lcs(i+1,j+1,k+1);

    }
    else
    {
        int res1=lcs(i+1,j,k);
        int res2=lcs(i,j+1,k);
        int res3=lcs(i,j,k+1);


        res1=max(res1,res3);
        return max(res1,res2);
    }
}

vector<string>vct;

void lcs_way(int i,int j,int k,int carry,int res,string st)
{
    if(i>=str1.size() || j>=str2.size() ||  k>=str3.size() )
    {
         return;
    }


    if(str1[i]==str2[j] && str3[k]==str2[j])
    {
        st+=str1[i];

          if(carry+1==res)
            vct.push_back(st);
        lcs_way(i+1,j+1,k+1,carry+1,res,st);

    }
    else
    {
        lcs_way(i+1,j,k,carry,res,st);
        lcs_way(i,j+1,k,carry,res,st);
        lcs_way(i,j,k+1,carry,res,st);
    }
}




int main()
{
    while(cin>>str1>>str2>>str3)
    {
        int res=lcs(0,0,0);
        string st;
        st.clear();
        lcs_way(0,0,0,0,res,st);

        for(int i=0 ;i<vct.size() ;i++)
        {
            cout<<vct[i]<<endl;
        }
        vct.clear();

    }


}

