#include<iostream>
#include<bits/stdc++.h>
using namespace std;



struct node
{
    string name;
    int hight;
    int income;
};


bool comp1(string a, string b)
{
    int mini=min(a.size(),b.size());
    {
        for(int i=0;i<mini;i++)
        {
            if(a[i]!=b[i])
            if((a[i]<='a' && a[i]<='z') && (b[i]<='a' && b[i]<='z'))

                    return a[i]<b[i];
            else
            {
                if((a[i]<='0' && a[i]<='9') && (b[i]<='a' && b[i]<='z'))
                  return a[i]>b[i];

                  if((a[i]<='a' && a[i]<='z') && (b[i]<='0' && b[i]<='9'))
                    return a[i]>b[i];

                    if((a[i]<='0' && a[i]<='9') && (b[i]<='0' && b[i]<='9'))
                      return a[i]<b[i];
            }
        }
    }
     return a.size()< b.size();
}

bool comp(node a,node b)
{
    if(a.income==b.income)
        if(a.hight==b.hight)
          return comp1(a.name,b.name);
        else
            return a.hight>b.hight;
    else
        return a.income>b.income;
}

int main()
{
    node st[5];

    for(int i=0;i<5;i++)
    {
        cin>>st[i].name;
        cin>>st[i].hight;
        cin>>st[i].income;
    }

    sort(st,st+5,comp);

     for(int i=0;i<5;i++)
    {
       cout<<st[i].name<<endl;
       cout<<st[i].hight<<endl;
       cout<<st[i].income<<endl;
    }

}
