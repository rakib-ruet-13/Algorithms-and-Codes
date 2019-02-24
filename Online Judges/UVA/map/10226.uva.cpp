#include<iostream>
#include<map>
#include<cstring>
#include<iterator>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
    map<string,int>tree;
    map<string,int>::iterator It;
    string str;
    double d;
    int cnt,i,j,tc;

    cin>>tc;
    getchar();
    getchar();
    while(tc--)
    {
        cnt=0;
        while(getline(cin,str) && str.size()!=0)
        {

             tree[str]++;
             cnt++;

       }


       for(It=tree.begin();It!=tree.end();It++)
       {
           cout<<It->first<<" ";
           d=(double)It->second/(double)cnt*100.00;
           printf("%.4f\n",d);
       }
       if(tc)
        cout<<endl;
       tree.clear();

    }
}
