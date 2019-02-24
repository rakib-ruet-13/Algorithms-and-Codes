#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int ind[10000000];

long long int  pre_process(string patt)

{

    long long int i,j,m;
    m=patt.size();

    ind[0]=0;
    j=0;
    for(i=1;i<m;i++)
    {
        if(patt[i]==patt[j])
        {
            ind[i]=j+1;
            j++;
        }

        else
        {
            do
            {
                j=ind[j-1];
                if(patt[i]==patt[j])
                {
                    j=j+1;
                    ind[i]=j;
                    break;
                }
            }
            while(j>0);

            if(j==0)
            {
              ind[i]=j;
            }
        }
    }
    return j;
}


int main()
{
    int ans,l;
    string str;

    while(cin>>str && str[0]!='.')
    {
        l=str.size();
        ans=l/(l-pre_process(str));
        cout<<ans<<endl;

        str.clear();
    }



}



