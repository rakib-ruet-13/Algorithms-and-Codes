#include<bits/stdc++.h>
#include<iostream>

#define Max 100010

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
#define FIO  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define CS(i) cout<<"Case :"<<i<<"\n";

using namespace std;



int T[4*Max+4];


int n;


///*****[L,R) format , root starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = 1;
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];
}

void update(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = 0;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid);
	else
		update(p, 2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];
}




int ask(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return T[id];
	int mid = (l + r)/2;
	return ask(x, y, id * 2, l, mid) +ask(x, y, id*2+1, mid, r) ;
}


/*******[L,R] formate *****/

struct node{

  int prop;
  int sum;
};

node T1[4*Max+4];

long long lazy_query(int id,int l,int r,int x,int y,int carry)
{
     if(l>y || r<x)
        return 0;

     else if(l>=x && r<=y)
    {
        return T1[id].sum+(r-l+1)*carry;

    }

     int mid=(l+r)/2;

    long  p1=lazy_query(2*id,l,mid,x,y,carry+T1[id].prop);
    long p2=lazy_query(2*id+1,mid+1,r,x,y,carry+T1[id].prop);

    return p1+p2;


}


int A[Max+1];

void lazy_init(int id,int l,int r)
{
    if(l==r)
    {
        T1[id].sum=A[l];
        T1[id].prop=0;
        return;
    }

    int mid=(l+r)/2;

    lazy_init(2*id,l,mid);
    lazy_init(2*id+1,mid+1,r);

    T1[id].sum=T1[2*id].sum+T1[2*id+1].sum;
    T1[id].prop=0;

}


void lazy_update(int id,int l,int r,int x,int y, int val)
{

    if(l>y || r<x)
        return;

    else if(l>=x && r<=y)
    {
        T1[id].sum+=(r-l+1)*val;
        T1[id].prop+=val;
        return;
    }

    int mid=(l+r)/2;

    lazy_update(2*id,l,mid,x,y,val);
    lazy_update(2*id+1,mid+1,r,x,y,val);

    T1[id].sum=T1[2*id].sum+T1[2*id+1].sum+(r-l+1)*T1[id].prop;

}






int main()
{



    return 0;
}
