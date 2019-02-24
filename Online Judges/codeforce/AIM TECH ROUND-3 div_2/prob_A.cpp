#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    string str;
    cin>>str;


    int flag=0;
    int flag2=0;

    for(int i=0 ; i<str.size() ; i++)
    {
        if(flag)
            break;

        if(str[i]!='a')
        {
            flag2=1;

            for(int j=i ; j<str.size() ; j++)
            {
                if(str[j]!='a')
                {
                    str[j]=char(str[j]-1);
                }
                else
                {
                    flag=1;
                    break;
                }
                flag=1;
            }
        }
    }

    if(flag2==0)
        str[str.size()-1]='z';

    cout<<str<<endl;





    return 0;
}

