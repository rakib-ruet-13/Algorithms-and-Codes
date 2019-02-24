#include<bits/stdc++.h>
#include<iostream>

#define Max 150010

#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define sz size()
#define scan(a) scanf("%lld",&a);
#define scani(a) a=read_int()
#define print(a) printf("%lld\n",a);
#define printi(a) printf("%d\n",a);
#define uu first
#define vv second
#define FIO  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define CS(i) cout<<"Case :"<<i<<"\n";

using namespace std;


long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}



int n;

/*******[L,R] formate *****/

struct node{

  ll prop;
  ll sum;
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


//int A[Max+1];

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




struct set_seg
{
    int l;
    int r;
};

set_seg seg[Max+2];

int Q[Max+2];
set<int>S;
set<int> :: iterator its;
map<int,int>mymap;
map<int,int> :: iterator itm;

int main()
{

    int tc;
    scani(tc);



    rep(cs,1,tc)
    {

        int q;
        scani(n);
        scani(q);

        for(int i=1; i<=n ; i++)
        {
            int l,r;
            scani(l);
            scani(r);

            if(l>r)
                swap(l,r);

            seg[i].l=l;
            seg[i].r=r;

            S.insert(l);
            S.insert(r);

        }

        for(int i=1; i<=q ; i++)
        {
            int temp;
            scani(temp);
            Q[i]=temp;
            S.insert(temp);
        }

        int tot=S.size();

        int k=1;
        for(its=S.begin() ; its!=S.end(); its++)
        {
            mymap[*its]=k++;
        }

        lazy_init(1,1,k);

        for(int i=1; i<=n ; i++)
        {
            lazy_update(1,1,k,mymap[seg[i].l],mymap[seg[i].r],1);
        }
        printf("Case %d:\n",cs);
        for(int i=1; i<=q; i++)
        {
            printf("%lld\n",lazy_query(1,1,k,mymap[Q[i]],mymap[Q[i]],0));
        }
        S.clear();
        mymap.clear();


    }



    return 0;
}

