#include<bits/stdc++.h>
#include<iostream>

#define Max 210010

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
		T[id]+= 1;
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


struct node
{
    int pos;
    int loc;
};

node red[Max];
node blue[Max];

bool comp(node a, node b)
{
    return a.pos<b.pos;
}

bool comp1(node a, node b)
{
    return a.pos>b.pos;
}


int main()
{
    int tc;
    scani(tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {
        int n;
        int m;
        scani(n);
        scani(m);

        for(int i=0; i<n ;i++)
        {
            int pos,loc;
            scani(pos);
            scani(loc);
            node temp;
            temp.pos=pos;
            temp.loc=loc;
            blue[i]=temp;
        }

         for(int i=0; i<m ;i++)
        {
            int pos,loc;
            scani(pos);
            scani(loc);
            node temp;
            temp.pos=pos;
            temp.loc=loc;
            red[i]=temp;
        }

        sort(blue,blue+n,comp);
        sort(red,red+m,comp);

        long long res=0;

        int k=0;

        build(1,0,Max+1);

        for(int i=0; i<m ; i++)
        {
            while(blue[k].pos<red[i].pos && k<n)
            {
                update(blue[k].loc,1,1,Max+1);
                k++;
            }

            res+=ask(red[i].loc,Max,1,1,Max+1);

        }

        sort(blue,blue+n,comp1);
        sort(red,red+m,comp1);

         build(1,0,Max+1);

         k=0;

        for(int i=0; i<m ; i++)
        {
            while(blue[k].pos>red[i].pos && k<n)
            {
                update(blue[k].loc,1,1,Max);
                k++;
            }

            res+=ask(1,red[i].loc+1,1,1,Max);

        }

        printf("Case %d: %lld\n",cs,res);



    }



    return 0;
}

