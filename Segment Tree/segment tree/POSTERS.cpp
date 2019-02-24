#include<iostream>
#include<bits/stdc++.h>
#define Max 400100

#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define sz size()
#define scan(a) scanf("%lld",&a);
#define scani(a) scanf("%d",&a);
#define print(a) printf("%lld\n",a);
#define printi(a) printf("%d\n",a);
#define uu first
#define vv second

using namespace std;



int n;


struct node{

  bool prop;
  bool sum;
};

node T1[4*Max+4];

bool lazy_query(int id,int l,int r,int x,int y,bool carry)
{
     if(l>y || r<x)
        return 1;

     else if(l>=x && r<=y)
    {
        return T1[id].sum || carry;

    }

     int mid=(l+r)/2;

    long  p1=lazy_query(2*id,l,mid,x,y,carry || T1[id].prop);
    long p2=lazy_query(2*id+1,mid+1,r,x,y,carry || T1[id].prop);

    return p1 && p2;

}


int A[Max+1];

void lazy_init(int id,int l,int r)
{
    if(l==r)
    {
        T1[id].sum=0;
        T1[id].prop=0;
        return;
    }

    int mid=(l+r)/2;

    lazy_init(2*id,l,mid);
    lazy_init(2*id+1,mid+1,r);

    T1[id].sum=T1[2*id].sum && T1[2*id+1].sum;
    T1[id].prop=0;

}


void lazy_update(int id,int l,int r,int x,int y, int val)
{

    if(l>y || r<x)
        return;

    else if(l>=x && r<=y)
    {
        T1[id].sum=1;
        T1[id].prop=1;
        return;
    }

    int mid=(l+r)/2;

    lazy_update(2*id,l,mid,x,y,val);
    lazy_update(2*id+1,mid+1,r,x,y,val);

    T1[id].sum=((T1[2*id].sum && T1[2*id+1].sum) || T1[id].prop);

}




int L[Max+1],R[Max+1];

int main()
{
    int tc;
    scani(tc);

    n=200002;
    int cs=1;

    while(tc--)
    {
        lazy_init(1,1,200002);
        int q;
        scani(q);
        for(int i=1; i<=q; i++)
        {
            int l,r;
            scani(L[i]);
            scani(R[i]);
        }

        int sum=0;

        for(int i=q; i>=1 ;i--)
        {
            if(lazy_query(1,1,200001,L[i],R[i],0)==0)
                sum++;

            lazy_update(1,1,200001,L[i],R[i],1);
        }
        printf("Case %d: ",cs++);
        printi(sum);


    }




    return 0;
}


