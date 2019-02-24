#include<bits/stdc++.h>
#include<iostream>

#define Max 800010

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


/*******[L,R] formate *****/

struct node{

  int prop;
  int a;
  int b;
  int c;

  node()
  {
      a=0;
      b=0;
      c=0;
      prop=0;
  }
};

node combine(node x,node y, node z)
{
    x.a=y.a+z.a;
    x.b=y.b+z.b;
    x.c=y.c+z.c;
    return x;
}

node T1[4*Max+4];

long long lazy_query(int id,int l,int r,int x,int y,int carry)
{

     if(l>y || r<x)
        return 0;



    if(l>=x && r<=y)
    {

        carry+=T1[id].prop;

        // cout<<"a b c="<<T1[id].a<<" "<<T1[id].b<<" "<<T1[id].c<<endl;
         if(carry%3==0)
         {
             return T1[id].a;
         }
         else if(carry%3==1)
         {
             return T1[id].c;
         }
         else
         {
             return T1[id].b;
         }


    }

     int mid=(l+r)/2;

    long  p1=lazy_query(2*id,l,mid,x,y,carry+T1[id].prop);
    long p2=lazy_query(2*id+1,mid+1,r,x,y,carry+T1[id].prop);

    return p1+p2;


}


int A[Max+1];

void lazy_init(int id,int l,int r)
{
    if(l==r)
    {
        T1[id].a=1;
        T1[id].prop=0;
        return;
    }

    int mid=(l+r)/2;

    lazy_init(2*id,l,mid);
    lazy_init(2*id+1,mid+1,r);

    T1[id]=combine(T1[id],T1[id*2],T1[id*2+1]);
    T1[id].prop=0;

}


void lazy_update(int id,int l,int r,int x,int y, int val)
{


    if(l>y || r<x)
        return;


     if(l>=x && r<=y)
    {

        T1[id].prop+=val;
        T1[id].prop%=3;

        if(T1[id].prop==0)
        {

        }
        else if(T1[id].prop==1)
        {
            int p,q,r;
            p=T1[id].a;
            q=T1[id].b;
            r=T1[id].c;

            T1[id].a=r;
            T1[id].b=p;
            T1[id].c=q;
        }
        else
        {
            int p,q,r;
            p=T1[id].a;
            q=T1[id].b;
            r=T1[id].c;

            T1[id].a=q;
            T1[id].b=r;
            T1[id].c=p;

        }

       // cout<<"a b c="<<T1[id].a<<" "<<T1[id].b<<" "<<T1[id].c<<endl;

        T1[id*2].prop+=T1[id].prop;
        T1[id*2+1].prop+=T1[id].prop;
        T1[id].prop=0;

        return;
    }

    int mid=(l+r)/2;

    lazy_update(2*id,l,mid,x,y,val);
    lazy_update(2*id+1,mid+1,r,x,y,val);


        /** calculationg left**/
        T1[2*id].prop%=3;

        if(T1[2*id].prop==0)
        {

        }
        else if(T1[2*id].prop==1)
        {
            int p,q,r;
            p=T1[2*id].a;
            q=T1[2*id].b;
            r=T1[2*id].c;

            T1[2*id].a=r;
            T1[2*id].b=p;
            T1[2*id].c=q;
        }
        else
        {
            int p,q,r;
            p=T1[2*id].a;
            q=T1[2*id].b;
            r=T1[2*id].c;

            T1[2*id].a=q;
            T1[2*id].b=r;
            T1[2*id].c=p;

        }


        T1[id*2*2].prop+=T1[id*2].prop;
        T1[(id*2)*2+1].prop+=T1[id*2].prop;
        T1[id*2].prop=0;

        /***calculationg right ***/
         T1[2*id+1].prop%=3;

        if(T1[2*id+1].prop==0)
        {

        }
        else if(T1[2*id+1].prop==1)
        {
            int p,q,r;
            p=T1[2*id+1].a;
            q=T1[2*id+1].b;
            r=T1[2*id+1].c;

            T1[2*id+1].a=r;
            T1[2*id+1].b=p;
            T1[2*id+1].c=q;
        }
        else
        {
            int p,q,r;
            p=T1[2*id+1].a;
            q=T1[2*id+1].b;
            r=T1[2*id+1].c;

            T1[2*id+1].a=q;
            T1[2*id+1].b=r;
            T1[2*id+1].c=p;

        }

        T1[(id*2+1)*2].prop+=T1[id*2+1].prop;
        T1[(id*2+1)*2+1].prop+=T1[id*2+1].prop;
        T1[id*2+1].prop=0;


        /*****combine ***/
         T1[id]=combine(T1[id],T1[id*2],T1[id*2+1]);

        /*****process current**/
        T1[id].prop%=3;

        if(T1[id].prop==0)
        {

        }
        else if(T1[id].prop==1)
        {
            int p,q,r;
            p=T1[id].a;
            q=T1[id].b;
            r=T1[id].c;

            T1[id].a=r;
            T1[id].b=p;
            T1[id].c=q;
        }
        else
        {
            int p,q,r;
            p=T1[id].a;
            q=T1[id].b;
            r=T1[id].c;

            T1[id].a=q;
            T1[id].b=r;
            T1[id].c=p;

        }



        T1[id*2].prop+=T1[id].prop;
        T1[id*2+1].prop+=T1[id].prop;
        T1[id].prop=0;
}






int main()
{
    int tc;
    scani(tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n,q;
        scani(n);
        scani(q);

        for(int i=0; i<=Max ;i++)
        {
            T1[i].a=T1[i].b=T1[i].c=0;
            T1[i].prop=0;
        }

        lazy_init(1,0,n-1);

        printf("Case %d:\n",cs);

        while(q--)
        {
            int a,x,y;
            scanf("%d %d %d",&a,&x,&y);

            if(a==0)
            {
                lazy_update(1,0,n-1,x,y,1);
            }
            else
            {
                printf("%lld\n",lazy_query(1,0,n-1,x,y,0));
            }
        }



    }



    return 0;
}


