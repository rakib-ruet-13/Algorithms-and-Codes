#include<iostream>
#include<bits/stdc++.h>
#define Max 400100
using namespace std;


long long int t;


long long st[Max];
long long ft[Max];

bool visited[Max];
long long int lvl[Max];
typedef long long ll;
vector<int>G[Max+1];



long long T[4*Max+4];

int arr[Max];

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = arr[l];
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


void dfs(int u)
{
    st[u]=t++;
    visited[u]=true;

    for(int i=0; i<G[u].size();i++)
    {

        int v=G[u][i];

        if(!visited[v])
        {
            lvl[v]=lvl[u]+1;
            dfs(v);
        }
    }
    ft[u]=t;
}



int main()
{

    int tc;
    scani(tc);
    int A[Max+2];


    for(int cs=1; cs<= tc ;cs++)
    {

    scani(n);

    for(int i=0 ; i< n; i++)
    {
        scani(A[i]);
    }


    for(int i=2; i<=n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        G[a].push_back(b);
    }

    t=1;

    memset(visited,0,sizeof(visited));
    memset(lvl,0,sizeof(lvl));


    dfs(0);

    for(int i=0; i<n ;i++)
    {
        arr[st[i]]=A[i];
    }


    int q;
    scanf("%d",&q);

    while(q--)
    {
        int p;
        scani(p);

        if(p==0)
        {
            scani(a);
            scani(b);

        }

        if(cs==1)
        {
           scanf("%lld %lld %lld",&V,&val,&K);

           range_update(st[V],ft[V],1,1,n+1);
        }
        else
        {
            res=sumk=0;
            scanf("%lld",&V);
            printf("%lld\n",ask(st[V],ft[V],1,1,n+1));

        }
    }





    return 0;
}

