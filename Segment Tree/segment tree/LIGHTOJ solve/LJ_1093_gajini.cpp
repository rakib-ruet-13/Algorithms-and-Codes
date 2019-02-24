/********************************************************/
/********************************************************/
/*************          RAKIB         *******************/
/************       CSE 13, RUET       ******************/
/***********          contact:           ****************/
/******     mail: rakib_cse13@outlook.com     ***********/
/*****           mobile : 01846207019           *********/
/********************************************************/
/********************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/******macros****/

#define Max 100005
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid (x>=1 && x<=col && y>=1 && y<=row)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define pii pair<ll,ll>

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



/***** useful function ****/

ll power(ll base, ll p){ ll ans=1;if(p==0)return 1;for(ll i=1;i<=p;i++)ans*=base;return ans;}
ll gcd(ll a, ll b){if(a==0)return b;gcd(b,a%b);}


/***** Nececessary global variables ****/

ll row,col;
int arr[Max];
int tree[Max*4];
int tree_mx[Max*4];

int ans=1000000000;
int ans1=-111111111;
int inf=1000000000;

/*****[L,R] formate with root 1 */
void init(int n,int start,int end)
{
    if(start==end)
    {
        tree[n]=arr[start];
        tree_mx[n]=arr[start];
        return ;
    }

    init(2*n,start,(start+end)/2);
    init(2*n+1,(start+end)/2+1,end);

    tree[n]=min(tree[2*n],tree[2*n+1]);
    tree_mx[n]=max(tree_mx[2*n],tree_mx[2*n+1]);
}


void query(int n,int start,int end,int rs,int re)
{
    if(end<rs || start>re)
           return;


    if(start>=rs && end<=re)
    {
        ans=min(ans,tree[n]);
        ans1=max(ans1,tree_mx[n]);
        return;
    }


    query(2*n, start, (start+end)/2,rs,re);
    query(2*n+1,(start+end)/2+1,end,rs,re);



}

int main()
{
     int n,tc,d;

     tc=read_int();

     for(int cs=1;cs<=tc;cs++)
     {

       n=read_int();
       d=read_int();

       mem(tree,31);
       mem(tree_mx,-1);

       for(int i=1;i<=n;i++)
       {
          arr[i]=read_int();
       }
       init(1,1,n);

       int maximum=-1111;
       int q1,q2;

       for(int i=1;i<=n;i++)
       {
           q1=i;
           q2=i+d-1;
           if(q2>n)
            q2=n;

           ans=1000000000;
           ans1=-11111111;
           query(1,1,n,q1,q2);
           maximum=max(maximum,ans1-ans);


       }
       printf("Case %d: %d\n",cs,maximum);

     }

     return 0;


}
