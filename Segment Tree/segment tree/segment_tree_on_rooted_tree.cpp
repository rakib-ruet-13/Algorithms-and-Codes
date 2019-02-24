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

struct node
{
    long long hkl;
    long long sk;
};

node T[4*Max+4];

long long mod;
int n;
long long int V,K,val,res,sumk;

void range_update(int x,int y, int id,int l,int r){//painting the interval [x,y) whith color "color"
	if(x >= r || l >= y)	return ;
	if(x <= l && r <= y){
        T[id].hkl+=val;
        T[id].hkl+=(K*lvl[V])%mod;
        T[id].hkl%=mod;

        T[id].sk+=K;
        T[id].sk%=mod;

		return ;
	}

	int mid = (l+r)/2;
	range_update(x, y, 2 * id, l, mid);
	range_update(x, y, 2*id+1, mid, r);
}


long long ask(int x,int y,int id,int l,int r)
{// [x, y)

    res=res+T[id].hkl+mod;
    res%=mod;

    sumk=T[id].sk%mod+mod;
    sumk%=mod;

    res=((res-(sumk*(ll)lvl[V])%mod)+mod)%mod;


	if(r-l<2)
    {// [l,r) is a subset of [x,y)
		return (res+mod)%mod;
    }
	int mid = (l + r)/2;

	if(x<mid)
	  return ask(x, y, id * 2, l, mid);

     return ask(x, y, id*2+1, mid, r) ;
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

    cin>>n;


    for(int i=2; i<=n;i++)
    {
        int temp;
        scanf("%d",&temp);
        G[temp].push_back(i);
    }

    t=1;

    memset(visited,0,sizeof(visited));
    memset(lvl,0,sizeof(lvl));
    mod=1000000007;

    dfs(1);

    for(int i=0; i<4*Max+4; i++)
    {
        T[i].hkl=0;


        //;juuvhvyvuy
        T[i].sk=0;
    }


    int q;
    scanf("%d",&q);

    while(q--)
    {
        int cs;
        scanf("%d",&cs);

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
