#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool cycle;

int par[100100];


int Find(int p)
{
    if(p==par[p])
        return p;
    else
        return par[p]=Find(par[p]);
}

void Union(int x,int y)
{
    int a,b;
    a=Find(x);
    b=Find(y);

    if(a!=b)
    {
        par[b]=par[a];
    }
    else
    {
        cycle=true;
    }
}



int main()
{

    int m,n;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        par[i]=i;

    cycle = false;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }

    if(!cycle && m==n-1)
    {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;



    return 0;


}
