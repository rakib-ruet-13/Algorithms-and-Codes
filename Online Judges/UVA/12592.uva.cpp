#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc,n,i,m;
    string str[100],st;

       cin>>n;
       getchar();

        for(i=0;i<2*n;i++)
        {
            getline(cin,str[i]);
        }
        cin>>m;
        getchar();

            for(i=0;i<m;i++)
            {
                getline(cin,st);
                for(int j=0;j<2*n;j+=2)
                {
                    if(str[j]== st)
                    {
                        cout<<str[j+1]<<endl;
                        break;
                    }
                }
                st.clear();

            }
            return 0;
}

