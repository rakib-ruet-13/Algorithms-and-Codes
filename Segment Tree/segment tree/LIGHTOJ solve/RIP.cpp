#include<bits/stdc++.h>
#include<iostream>

#define Max 300010

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

using namespace std;



/*******[L,R] formate *****/

struct node{

  long long int prop1,prop2,prop3;
  bool up1,up2,up3;
  long long int sum;
};



node T[4*Max+4];

long long int get_range_sum(long long int l, long long int  r)
{
    if(l>r)
    swap(l,r);

    return (r*(r+1))/2 - (l*(l-1))/2;
}

void update_child(ll id,ll l, ll mid, ll r, ll op)
{
    ll left=id*2;
    ll right=left+1;

    if(op==1)
    {
        if(l!=r)
        {
        T[left].prop1+=T[id].prop1;
        T[right].prop1+=T[id].prop1;

        T[left].sum+=T[left].prop1*get_range_sum(l,mid);
        T[right].sum+=T[right].prop1*get_range_sum(mid+1,r);

        T[left].up1=T[right].up1=true;

        T[id].up1=false;
        T[id].prop1=0;
        T[id].sum=T[left].sum+T[right].sum;
        }


    }
    else if(op==2)
    {
        if(l!=r)
        {
        T[left].prop2+=T[id].prop2;
        T[right].prop2+=T[id].prop2;

        T[left].sum+=T[left].prop2*(mid-l+1);
        T[right].sum+=T[right].prop2*(r-mid);

        T[left].up2=T[right].up2=true;

        T[id].up2=false;
        T[id].prop2=0;
        T[id].sum=T[left].sum+T[right].sum;


        }

    }
    else if(op==3)
    {
        if(l!=r)
        {
        T[left].prop3=T[id].prop3;
        T[right].prop3=T[id].prop3;

        T[left].sum=T[left].prop3*(mid-l+1);
        T[right].sum=T[right].prop3*(r-mid);

        T[left].up3=T[right].up3=true;

        T[id].up3=false;
        T[id].prop3=0;
        T[id].sum=T[left].sum+T[right].sum;


        /***  cancelling the other propagation  ***/
        T[id].prop1=T[left].prop1=T[right].prop1=0;
        T[id].up1=T[left].up1=T[right].up1=0;


        T[id].prop2=T[left].prop2=T[right].prop2=0;
        T[id].up2=T[left].up2=T[right].up2=0;



        }

    }


}

void topdown_update(ll id,ll l,ll mid, ll r)
{


    if(T[id].up1)
    {
       update_child(id, l,mid, r,1);
    }

    if(T[id].up2)
    {
         update_child(id, l,mid, r,2);
    }
    if(T[id].up3)
    {
        update_child(id, l,mid, r,3);
    }

}

void lazy_init(ll int id,ll int l,ll int r)
{
    if(l==r)
    {
        T[id].sum=0;
        T[id].prop1=T[id].prop2=T[id].prop3=0;
        T[id].up1=T[id].up2=T[id].up3=false;
        return;
    }

    int mid=(l+r)/2;

    lazy_init(2*id,l,mid);
    lazy_init(2*id+1,mid+1,r);

    T[id].sum=T[2*id].sum+T[2*id+1].sum;
    T[id].prop1=T[id].prop2=T[id].prop3=0;
    T[id].up1=T[id].up2=T[id].up3=false;

}



void update1(ll int id,ll int l,ll int r,ll int x,ll int y, ll int val)
{

    /****if there is update we shold take it to down **/


    if(l>y || r<x)
        return;

    topdown_update(id,l,(l+r)/2,r);

     if(l>=x && r<=y)
    {
        T[id].sum+=get_range_sum(l,r)*val;
        T[id].prop1+=val;
        T[id].up1=true;

        topdown_update(id,l,(l+r)/2,r);
        T[id].prop1=0;
        T[id].up1=false;

        return;
    }
         topdown_update(id,l,(l+r)/2,r);

    ll int mid=(l+r)/2;

    update1(2*id,l,mid,x,y,val);
    update1(2*id+1,mid+1,r,x,y,val);

    T[id].sum=T[2*id].sum+T[2*id+1].sum;

}



void update2(ll int id,ll int l,ll int r,ll int x,ll int y, ll int val)
{

    if(l>y || r<x)
        return;

     topdown_update(id,l,(l+r)/2,r);

     if(l>=x && r<=y)
    {
        T[id].sum+=(r-l+1)*val;
        T[id].prop2+=val;
        T[id].up2=true;

        topdown_update(id,l,(l+r)/2,r);
        T[id].prop2=0;
        T[id].up2=false;
        return;
    }
    topdown_update(id,l,(l+r)/2,r);
    ll int mid=(l+r)/2;

    update2(2*id,l,mid,x,y,val);
    update2(2*id+1,mid+1,r,x,y,val);

    T[id].sum=T[2*id].sum+T[2*id+1].sum;

}



void update3(ll int id,ll int l,ll int r,ll int x,ll int y, ll int val)
{

    if(l>y || r<x)
        return;

     topdown_update(id,l,(l+r)/2,r);


    if(l>=x && r<=y)
    {
        T[id].sum=(r-l+1)*val;
        T[id].prop3=val;
        T[id].up3=true;

        topdown_update(id,l,(l+r)/2,r);
        T[id].prop3=0;
        T[id].up3=false;

        return;
    }

    topdown_update(id,l,(l+r)/2,r);

    ll int mid=(l+r)/2;

    update3(2*id,l,mid,x,y,val);
    update3(2*id+1,mid+1,r,x,y,val);

    T[id].sum=T[2*id].sum+T[2*id+1].sum;

}





long long int lazy_query(ll  int id,ll  int l, ll int r, ll int x,ll int y)
{
     if(l>y || r<x)
        return 0LL;

    topdown_update(id,l,(l+r)/2,r);

     if(l>=x && r<=y)
    {
        return T[id].sum;

    }

     topdown_update(id,l,(l+r)/2,r);

     ll int mid=(l+r)/2;

     ll int   p1=lazy_query(2*id,l,mid,x,y);
     ll int p2=lazy_query(2*id+1,mid+1,r,x,y);

    return p1+p2;
}









int main()
{

    //freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);
    for(int cs=1 ; cs<=tc ; cs++)
    {

        lazy_init(1,1,Max);

        printf("Case %d:\n",cs);

        int q;
        scanf("%d",&q);

        for(int k=1; k<=q ;k++)
        {
            getchar();
            char ch;
            ll int a,b;
            scanf("%c %lld %lld",&ch,&a,&b);

            if(ch=='A')
            {
               update1(1,1,Max,a,b,1);

               update2(1,1,Max,a,b,1-a);

            }
            else if(ch=='B')
            {
                update1(1,1,Max,a,b,-1);

                update2(1,1,Max,a,b,b+1);

            }
            else if(ch=='C')
            {
                ll x;
                scanf("%lld",&x);
                update3(1,1,Max,a,b,x);
            }
            else
            {
                ll res=lazy_query(1,1,Max,a,b);
                printf("%lld\n",res);
            }

        }

        for(int id=0; id<=Max*4 ; id++)
        {
           T[id].sum=0;
           T[id].prop1=T[id].prop2=T[id].prop3=0;
           T[id].up1=T[id].up2=T[id].up3=false;
        }
    }



    return 0;
}

