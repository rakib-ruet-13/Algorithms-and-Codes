#include<iostream>
#include<bits/stdc++.h>
#define Max 40010
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


struct node
{
   vector<int>vct;
};

node T[4*Max+4];
int arr1[Max+1];

int n;
int K;



///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
       // T[id].vct.clear();
		T[id].vct.push_back(arr1[l]);
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	//T[id].vct.clear();
	merge(T[id*2].vct.begin(),T[id*2].vct.end(),T[id*2+1].vct.begin(),T[id*2+1].vct.end(),back_inserter(T[id].vct));
}




int ask(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		{
		    int res=T[id].vct.size()- (upper_bound(T[id].vct.begin(),T[id].vct.end(),K)-T[id].vct.begin());
		    return res;

		}
	int mid = (l + r)/2;
	return ask(x, y, id * 2, l, mid) +ask(x, y, id*2+1, mid, r) ;
}





int main()
{

    int n;
    scani(n);

    rep(i,0,n-1)
    {
        scani(arr1[i]);
    }

    build(1,0,n);

    int pre_res=0;

    int q;
    scani(q);

    while(q--)
    {
        int a,b,c,i,j;
        scani(a);
        scani(b);
        scani(c);
        i=a^pre_res;
        j=b^pre_res;
        K=c^pre_res;

        pre_res=ask(i-1,j,1,0,n);

        printi(pre_res);
    }


    return 0;
}


