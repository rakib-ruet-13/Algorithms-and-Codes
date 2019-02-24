#include<iostream>
#include<bits/stdc++.h>
#define Max 1000100
using namespace std;




struct node
{
    int a;
    int b;
    int c;
};
node T[4*Max+4];
node arr[Max+1];
node zero;

node operator+ (node x,node y)
{
    node z;
    int t=min(x.b,y.c);

    z.a=x.a+y.a+2*t;
    z.b=x.b+y.b-t;
    z.c=x.c+y.c-t;
    return z;

}

int n;


///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = arr[l];
		//cout<<"l="<<l<< arr[l].a<<" "<<arr[l].b<<endl;
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];

	//cout<<"id= "<<id<<"   ans= "<<T[id].a<<endl;
}

void update(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = zero;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid);
	else
		update(p, 2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];
}




node ask(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return zero;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return T[id];
	int mid = (l + r)/2;
	return ask(x, y, id * 2, l, mid) +ask(x, y, id*2+1, mid, r) ;
}




int main()
{

    string str;

        zero.a=0;
    zero.b=0;
    zero.c=0;



    cin>>str;
    n=str.size();





    for(int i=0; i<str.size(); i++)
    {
        node temp;
        temp.a=temp.b=temp.c=0;

        if(str[i]=='(')
            temp.b=1;
        else
            temp.c=1;

        arr[i]=temp;
    }

     build(1,0,n);

    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;

        if(a>b)
        swap(a,b);

        cout<<ask(a-1,b,1,0,n).a<<endl;
    }






}
