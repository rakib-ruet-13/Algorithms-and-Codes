#include<iostream>
#include<bits/stdc++.h>
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

using namespace std;

multiset<int>T[4*Max+4];


int n;


///*****[L,R) format , oot starts with 1*****//


void update(int p,int id = 1,int l = 0,int r = n+1,int val=0){

	T[id].insert(val);
	//cout<<id<<" "<<l<<" "<<r<<" "<<val<<endl;

	if(r - l < 2){
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid,val);
	else
		update(p, 2 * id + 1, mid, r,val);
}




int ask(int x,int y,int id = 1,int l = 0,int r = n,int val=0){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return T[id].count(val);

	int mid = (l + r)/2;
	return ask(x, y, id * 2, l, mid,val) +ask(x, y, id*2+1, mid, r,val) ;
}







int main()
{

    int q;
    scani(q);
    n=10000;

    while(q--)
    {
        int a;
        scani(a);

        if(a==1)
        {
            int pos, val;
            scani(pos);
            scani(val)

            update(pos,1,0,n+1,val);

        }
        else
        {
            int l,r,val;
            scani(l);
            scani(r);
            scani(val);
            cout<<ask(l,r+1,1,0,n+1,val)<<endl;


        }
    }



    return 0;
}

