#include<bits/stdc++.h>
#include<iostream>

#define Max 724728

#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define sz size()
#define scan(a) scanf("%lld",&a);
#define scani(a) scanf("%d",&a);
#define printa(a) printf("%lld\n",a);
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
		T[id] = 1;
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


/***** ask with no need of binary search *****/

int ask(int id = 1,int l = 1,int r = n+1,int sum=0){// [x, y)
    if(r - l < 2){
		return l;
	}


    if(T[id]>=sum)
    {
        int mid=(l+r)/2;

        if(T[id*2]>=sum)
          ask(id*2,l,mid,sum);
        else
          ask(id*2+1,mid,r,sum-T[id*2]);
    }
    else
        return 11111111;

}




int get_index(int k)
{
    int p=ask(1,1,Max+2,k);
    return p;
}


int main()
{

    vector<int>vct;
    vct.push_back(0);

    memset(T,0,sizeof(T));

   for(int i=1  ; i<=Max*2+10; i+=2)
   {
        vct.push_back(i);
   }
   //cout<<vct.size()<<endl;
   build(1,1,Max+2);


   int tot=2;
   int cnt=Max+1;

   while(1)
   {
       int real=get_index(tot);

       if(real>=Max)
        break;

       int inc=vct[real];

       vector<int>que;

       for(int i=inc ; i<=cnt+1 ; i+=inc)
       {
           int p=get_index(i);
           que.push_back(p);
       }


       for(int i=0; i<que.size() ; i++)
       {
           if(que[i]<=cnt)
            update(que[i],1,1,Max+2);

       }
       que.clear();


       tot++;

   }

   int tc;
   scanf("%d",&tc);

   for(int cs=1 ; cs<=tc ;cs++)
   {
       int p;
       scani(p);
       printf("Case %d: %d\n",cs,vct[ask(1,1,Max+2,p)]);
   }

    return 0;
}


