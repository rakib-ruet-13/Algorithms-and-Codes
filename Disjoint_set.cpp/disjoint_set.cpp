#include<iostream>
#include<bits/stdc++.h>
#define Max 100000

using namespace std;

int par[Max+1];

void init(int n)
{
    for(int i=1;i<=n; i++)
        par[i]=i;
}

int find(int n)
{
    if(par[n]==n)
        return n;
    else
        return par[n]=find(par[n]);
}

int main()
{

    freopen("input.txt","r",stdin);
    int n,a,b;

    scanf("%d",&n);

    init(n);
    int ns=n;
    for(int i=1;i<=n;i++)
    {
       scanf("%d %d",&a,&b);
       int u=find(a);
       int v=find(b);
       if(u!=v)
       {

            par[v]=u;
            ns--;
       }



    }
    cout<<ns<<endl;

    //for(int i=1 ;i<=n; i++)
       {
           //cout<<find(i)<<" ** "<<endl;
       }
    while(cin>>a)
    {
        cout<<"Par of  "<<a<<" = "<<par[a]<<endl;
    }
    return 0;
}
