#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int rev(int n)
{
    int p=0;

    while(n)
    {
        p=p*10+n%10;
        n=n/10;
    }

    return p;
}


int main()
{
    vector<int>vct;
    for(int i=0 ; i<=100000; i++)
    {
        if(rev(i)==i)
            {
                vct.push_back(i);


            }

              if(i==10 || i==100 || i==1000 || i==10000 || i==90000)
                    cout<<i<<"  "<<vct.size()-1<<endl;
    }
    //for(int i=10; i<300 ; i*=)
    {
       // cout<<i<<"  "<<vct[i]<<endl;
    }
}
