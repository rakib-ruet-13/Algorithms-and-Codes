#include<iostream>
#include<bits/stdc++.h>
#define Max 400010
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
struct node1
{
    int ind;
    int val;
};


int T[4*Max+4];
node1 arr[Max+1];
int arr1[Max+1];

int n;


struct node
{
    int ind;
    int l;
    int r;
    int k;
    int res;
};


///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = 0;
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];
}

void update(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] =1;
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



bool comp( node a, node b)
{
    return a.k>b.k;
}

bool comp1(node a, node b)
{
    return a.ind<b.ind;
}

bool comp2(node1 a,node1 b)
{
    return a.val<b.val;
}



int main()
{
    int n;
    scani(n);
    build(1,0,n);

    rep(i,0,n-1)
    {
        scani(arr[i].val);
        arr[i].ind=i;
        arr1[i]=arr[i].val;
    }

    sort(arr,arr+n,comp2);

    int q;
    scani(q);

    vector<node>ques;

    int t=1;

    while(q--)
    {
        int lo,hi,k;
        scani(lo);
        scani(hi);
        scani(k);

        node tmp;
        tmp.l=lo;
        tmp.r=hi;
        tmp.k=k;
        tmp.ind=t;
        t++;

        ques.pb(tmp);


    }


    sort(ques.begin(),ques.end(),comp);

    int point=n-1;

    for(int i=0; i<ques.size(); i++)
    {
        while(arr[point].val>ques[i].k && point>=0)
        {
            update(arr[point].ind,1,0,n);
            point--;
        }

        ques[i].res=ask(ques[i].l-1,ques[i].r,1,0,n);

    }

     sort(ques.begin(),ques.end(),comp1);

     for(int i=0; i<ques.size();i++)
     {
         printi(ques[i].res);
     }



    return 0;
}

