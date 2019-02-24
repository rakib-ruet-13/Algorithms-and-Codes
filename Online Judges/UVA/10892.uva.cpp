#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

long long int GCD(long long a,long long b)
{
    if(a%b==0)
        return b;
    GCD(b,a%b);
}

long long int LCM(long long int a,long long int b)
{
    return a*b/GCD(a,b);
}

int main()
{
    long long int tc,l,num,Max,j,k,i,cnt;

    vector<int>vct;

    while(cin>>num && num!=0)
    {
        Max=sqrt(num);

        for(i=1;i<=Max;i++)
        {
           if(num%i==0)
           {
            vct.push_back(i);
             if(!(i*i==num))
              vct.push_back(num/i);
           }

        }

        l=vct.size();
        cnt=1;

        for(i=0;i<l-1;i++)
        {
            for(j=i+1;j<l;j++)
            {
                if(LCM(vct[i],vct[j])==num)
                    cnt++;
            }
        }
        cout<<num<<" "<<cnt<<endl;

        vct.clear();



    }

    return 0;

}


