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

void update(int p,int id = 1,int l = 0,int r = n,int val=0){
	if(r - l < 2){
		T[id] = val;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid,val);
	else
		update(p, 2 * id + 1, mid, r,val);
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


struct quer
{
    int l; int r; int ind;
};


quer Q[Max+2];

bool comp(quer a, quer b)
{
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}


map<int,int>map_flag;
map<int,int>map_ind;

int arr[Max+2];
int main()
{
    int tc;
    scani(tc);

    int ans[Max+2];

    for(int cs=1 ; cs<=tc ; cs++)
    {
        int n,q;
       scani(n);
       scani(q);

       rep(i,1,n)
       scani(arr[i]);

       build(1,0,n+1);

       printf("Case %d:\n",cs);

       for(int i=1; i<=q; i++)
       {
           int p,q;
           scani(p);
           scani(q);

           Q[i-1].ind=i;
           Q[i-1].l=p;
           Q[i-1].r=q;
       }

       sort(Q,Q+q,comp);

       int curr=1;

       for(int i=0 ; i<q ; i++)
       {
           int left=Q[i].l;
           int right=Q[i].r;
           int ind=Q[i].ind;

           while(curr<=right)
           {
              int p=arr[curr];

              if(map_flag[p]==0)
              {
                  update(curr,1,1,n+1,1);
                  map_flag[p]=1;
                  map_ind[p]=curr;
              }
              else
              {
                  update(curr,1,1,n+1,1);
                  update(map_ind[p],1,1,n+1,0);

                  map_ind[p]=curr;
              }

              curr++;
           }

           int res=ask(left,right+1,1,1,n+1);
           ans[ind]=res;

       }

       map_flag.clear();
       map_ind.clear();


       for(int i=1; i<=q ; i++)
        printf("%d\n",ans[i]);
    }



    return 0;
}


