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




/*******[L,R] formate *****/

struct node{

  int prop;
  int sum;
  int upd;

};

int n;

node T1[4*Max+4];


void update_child(int id, int l, int r, int mid)
{
    int left= id*2;
    int right= id*2+1;

    T1[left].prop=T1[id].prop;
    T1[right].prop=T1[id].prop;

    T1[left].sum=T1[id].prop*(mid-l+1);
    T1[right].sum=T1[id].prop*(r-mid);

    T1[left].upd=1;
    T1[right].upd=1;

    T1[id].upd=0;
    T1[id].prop=0;

}
long long lazy_query(int id,int l,int r,int x,int y,int carry)
{
     if(l>y || r<x)
        return 0;

     else if(l>=x && r<=y)
    {
        return T1[id].sum;

    }


     int mid=(l+r)/2;

      if(T1[id].upd)
    update_child(id,l,r,mid);



    long  p1=lazy_query(2*id,l,mid,x,y,carry+T1[id].prop);
    long p2=lazy_query(2*id+1,mid+1,r,x,y,carry+T1[id].prop);

    return p1+p2;


}


int A[Max+1];

void lazy_init(int id,int l,int r)
{
    if(l==r)
    {
        T1[id].sum=0;
        T1[id].prop=0;
        T1[id].upd=0;
        return;
    }

    int mid=(l+r)/2;

    lazy_init(2*id,l,mid);
    lazy_init(2*id+1,mid+1,r);

    T1[id].sum=T1[2*id].sum+T1[2*id+1].sum;
    T1[id].prop=0;
    T1[id].upd=0;

}


void lazy_update(int id,int l,int r,int x,int y, int val)
{

    if(l>y || r<x)
        return;

    else if(l>=x && r<=y)
    {
        T1[id].sum=(r-l+1)*val;
        T1[id].prop=val;
        T1[id].upd=1;
        return;
    }

    int mid=(l+r)/2;

    if(T1[id].upd)
    update_child(id,l,r,mid);

    lazy_update(2*id,l,mid,x,y,val);
    lazy_update(2*id+1,mid+1,r,x,y,val);

    T1[id].sum=T1[2*id].sum+T1[2*id+1].sum;


}


int main()
{

    int tc;

    scani(tc);


    for(int cs=1 ; cs<= tc ; cs++)
    {
       // t=0;
        int n,q;
        scani(n);
        scani(q);

        lazy_init(1,0,n);


        printf("Case %d:\n",cs);

        while(q--)
        {

            int x,y,z;
            scani(x);

            if(x==1)
            {
                int p,q,r;


                scanf("%d %d %d",&p,&q,&r);
                 if(p>q)
                    swap(p,q);
                p++;
                q++;


                lazy_update(1,1,n,p,q,r);

            }
            else if(x==2)
            {
                int p,q;


                scanf("%d %d",&p,&q);
                  if(p>q)
                    swap(p,q);
                    p++;
                    q++;

                long long res=lazy_query(1,1,n,p,q,0);

               // cout<<"sum = "<<res<<endl;
                int div=(q-p+1);

                int g=__gcd((int)res, div);

                res/=g;
                div/=g;
                if(div==1)
                   printf("%lld\n",res);
                else
                    printf("%lld/%d\n",res,div);
            }
        }


    }



    return 0;
}
