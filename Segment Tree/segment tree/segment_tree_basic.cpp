#include<iostream>
#include<bits/stdc++.h>
#define Max 100100
using namespace std;

int T[2*Max+4];


void build(int n)
{
    for(int i=n-1; i>0 ;i--)   // arr value 0 starts from n;
        T[i]=T[i<<1]+T[i<<1|1];
}

void modify(int p,int value,int n)
{
    for( T[p+=n]=value ; p>1 ; p>>=1 ) // p+n indicates the position on the array
        T[p>>1]=T[p]+T[p^1];
}

int query(int l, int r,int n)
{
    int res=0;
    for(l+=n,r+=n ; l<r ; l>>=1 , r>>=1) // it works for interval [l,r) ##right not inclusive
    {
        if(l&1) res+=T[l++];
        if(r&1) res+=T[--r]; // immidiate decrement
    }

    return res;

}



int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n ;i++)
    {
        scanf("%d",T+n+i);
    }
    build(n);

    modify(3,5,n);

    printf("%d\n",query(0,2,n));


    return 0;
}
