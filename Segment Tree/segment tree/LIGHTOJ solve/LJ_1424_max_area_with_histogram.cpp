#include<iostream>
#include<bits/stdc++.h>
#define Max 1002

#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define scan(a) scanf("%lld",&a);
#define scani(a) scanf("%d",&a);
#define print(a) printf("%lld\n",a);
#define printi(a) printf("%d\n",a);
#define uu first
#define vv second
#define FIO  ios_base::sync_with_stdio(false)
#define CS(i) cout<<"Case :"<<i<<"\n";

using namespace std;

char A[1002][1002];
int pre[1002][1002];

vector<int>vct;
int sz;


struct node
{
    int mn;
    int ind;
};

node T[4*Max+4];


int n;
int arr[Max];

///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){


		T[id].mn= arr[l];
		T[id].ind=l;
        		return ;
	}

	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);

	if(T[2*id].mn<T[2*id+1].mn)
    {
        T[id].mn=T[2*id].mn;
        T[id].ind=T[2*id].ind;
    }
	else
    {
        T[id].mn=T[2*id+1].mn;
        T[id].ind=T[2*id+1].ind;

    }
}



node inf;

node ask(int x,int y,int id = 1,int l = 0,int r = n){

    // [x, y)
	if(x >= r or l >=y)	return inf;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		{

		     return T[id];

		}

	int mid = (l + r)/2;

	node a1=ask(x, y, id * 2, l, mid);
	node a2=ask(x, y, id *2 +1, mid, r);


	if(a1.mn<a2.mn)
        return a1;
    else
        return a2;
}


long long mx;

void cnt(int l = 1,int r = n){


    if(l>r)
        return;


    node p=ask(l,r+1,1,1,n+1);
    int mid = p.ind;

    mx=max(mx, (long long)(p.mn*(r-l+1)));

    if(l>=r)
        return;

    cnt(l, mid-1);
    cnt(mid+1, r);

}





long long histogram(int sz)
{

    inf.mn=11111111;
    inf.ind=0;


        n=sz;

        mx=-1;
        for(int i=1; i<=n ;i++)
           arr[i]=vct[i];

        build(1,1,n+1);
        cnt(1,n);

        return mx;
}





int main()
{
    freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        getchar();

        for(int i=1; i<=n ;i++)
            for(int j=1; j<=m; j++)
        {
            scanf("%c",&A[i][j]);

            if(j==m)
                getchar();
        }

        for(int i=0; i<=1001; i++)
            for(int j=0; j<=1001; j++)
        {
            pre[i][j]=0;
        }

        for(int i=1 ;i<=n ;i++)
            for(int j=m ; j>0 ; j--)
        {
            if(A[i][j]!='0')
                pre[i][j]=0;
            else
                pre[i][j]=pre[i][j+1]+1;
        }

          /*
          for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                printf("%d ",pre[i][j]);
                if(j==m)
                    printf("\n");
            }
            */


          long long int res=0;

          for(int j=1; j<=m; j++)
          {
            vct.push_back(0);

            for(int i=1; i<=n; i++)
            {
              vct.push_back(pre[i][j]);
            }

           sz=n;


           res=max(res,histogram(sz));
           vct.clear();

          }

          printf("Case %d: %lld\n",cs,res);

    }



    return 0;
}
