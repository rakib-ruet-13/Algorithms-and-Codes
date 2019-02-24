#include<iostream>
#include<bits/stdc++.h>
#define Max 10001

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

int Ts[4*Max+4];



int n;


///*****[L,R) format , oot starts with 1*****//

void build1(int id = 1,int l = 0,int r = n+1){
	if(r - l < 2){
		Ts[id] = 0;
		return ;
	}
	int mid = (l+r)/2;
	build1(2 * id, l, mid);
	build1(2 * id + 1, mid, r);
	Ts[id] = Ts[2 * id] + Ts[2 * id + 1];
}



void update1(int p,int id = 1,int l = 0,int r = n+1){
	if(r - l < 2){
		Ts[id] += 1;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update1(p, 2 * id, l, mid);
	else
		update1(p, 2 * id + 1, mid, r);
	Ts[id] = Ts[2 * id] + Ts[2 * id + 1];
}




int ask1(int x,int y,int id = 1,int l = 0,int r = n+1){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return Ts[id];
	int mid = (l + r)/2;
	return ask1(x, y, id * 2, l, mid) +ask1(x, y, id*2+1, mid, r) ;
}


/*******[L,R] formate *****/

struct node{

  int prop;
  int mx;
  int ind;
};
node zero;

node operator+ (node a, node b)
{
    node temp;
    if(a.mx>b.mx)
    {
        temp.mx=a.mx;
        temp.ind=a.ind;
    }
    else
    {
        temp.mx=b.mx;
        temp.ind=b.ind;
    }

    return temp;
}

node T1[4*Max+4];


int A[Max+1];

void lazy_init(int id,int l,int r)
{
    if(l==r)
    {
        T1[id].mx=A[l];
        T1[id].ind=l;
        T1[id].prop=0;
        return;
    }

    int mid=(l+r)/2;

    lazy_init(2*id,l,mid);
    lazy_init(2*id+1,mid+1,r);

    T1[id]=T1[2*id]+T1[2*id+1];
    T1[id].prop=0;

}



node lazy_query(int id,int l,int r,int x,int y,int carry)
{
     if(l>y || r<x)
        return zero;

     else if(l>=x && r<=y)
    {
        node temp;
        temp.mx=T1[id].mx+carry;
        temp.ind=T1[id].ind;

        return temp;

    }

     int mid=(l+r)/2;

    node  p1=lazy_query(2*id,l,mid,x,y,carry+T1[id].prop);
    node p2=lazy_query(2*id+1,mid+1,r,x,y,carry+T1[id].prop);

    return p1+p2;


}




void lazy_update(int id,int l,int r,int x,int y, int val)
{

    if(l>y || r<x)
        return;

    else if(l>=x && r<=y)
    {
        T1[id].mx+=val;
        T1[id].prop+=val;
        return;
    }

    int mid=(l+r)/2;

    lazy_update(2*id,l,mid,x,y,val);
    lazy_update(2*id+1,mid+1,r,x,y,val);

    node temp;
    temp=T1[2*id]+T1[2*id+1];
    T1[id].mx=temp.mx;
    T1[id].ind=temp.ind;

    T1[id].mx+=T1[id].prop;

}







int main()
{
    //cout<<"ok"<<endl;;
    zero.mx=-11111111;
    zero.ind=0;
    zero.prop=0;


    int n;
    scani(n);

    rep(i,1,n)
    scani(A[i]);

    build1(1,0,n+1);
    lazy_init(1,1,n);

    int q;
    scani(q);

    while(q--)
    {
        int a;
        scani(a);



        if(a==1)
        {
            int x,y,k;
            scani(x);
            scani(y);
            scani(k);

            while(1)
            {
                node p;
                p=lazy_query(1,1,n,1,n,0);
                if(p.mx<k)
                    break;
                else
                {
                    lazy_update(1,1,n,p.ind,p.ind,-111111);
                    update1(p.ind,1,0,n+1);
                }
            }
            cout<<ask1(x,y+1,1,0,n+1)<<endl;;
        }
        else
        {
            int x,y;
            scani(x);
            scani(y);

            lazy_update(1,1,n,x,y,1);
        }


    }



   return 0;
}




