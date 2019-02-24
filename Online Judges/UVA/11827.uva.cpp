#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
//#include<bits/stdc++.h>
using namespace std;

long long int GCD(long long a,long long b)
{
    if(a%b==0)
        return b;
    GCD(b,a%b);
}

int main()
{
    long long int tc,l,num,Max,j,k,i;
    string str;
    vector<int>vct;
    cin>>tc;
    getchar();
    while(tc--)
    {
        getline(cin,str);
        l=str.size();
        i=0;
        num=0;
        while(i!=l)
        {
            if(str[i]==' ')
            {
                vct.push_back(num);
                num=0;
                i++;
            }
            else
            num=num*10+str[i++]-48;

        }
        if(num!=0)
        vct.push_back(num);

        l=vct.size();
        Max=1;

        for(i=0;i<l-1;i++)
        {
            for(j=i+1;j<l;j++)
            {
                k=GCD(vct[i],vct[j]);
                if(k>Max)
                    Max=k;
            }
        }
        cout<<Max<<endl;

        vct.clear();
        str.clear();



    }

    return 0;

}

