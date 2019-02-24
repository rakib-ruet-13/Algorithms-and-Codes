#include<bits/stdc++.h>
#include<iostream>

#define Max 280004

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


int n;
int tim;
/*******[L,R] formate *****/

struct node{

  long long int prop1;
  int long long prop2;
  long long int prop3;

  int upd1;
  int upd2;
  int upd3;

  int upd1_time;
  int upd2_time;
  int upd3_time;

  long long int sum;
};

node T1[4*Max+4];



long long get_range_sum(long long l, long long r)
{
    if(l>r)
    swap(l,r);

    return (r*(r+1))/2 - (l*(l-1))/2;
}


void update_child(int id,int l,int mid,int r,int op)
{
    int left=id*2;
    int right= id*2+1;

    if(op==1)
    {
        if(l!=r)
        {

        T1[left].prop1+=T1[id].prop1;
        T1[right].prop1+=T1[id].prop1;

        T1[left].sum+=get_range_sum(l,mid)*T1[id].prop1;
         T1[right].sum+=get_range_sum(mid+1,r)*T1[id].prop1;

        T1[left].upd1_time=T1[id].upd1_time;
        T1[right].upd1_time=T1[id].upd1_time;

         T1[left].upd1=1;
         T1[right].upd1=1;

         T1[id].prop1=0;
         T1[id].upd1=0;
        }
        else
        {
            /*
            T1[id].sum+=get_range_sum(l,r)*T1[id].prop1;
            T1[id].prop1=0;
            T1[id].upd1=0;
            */

        }
    }
    else if(op==2 )
    {

        if(l!=r)
        {

        T1[left].prop2+=T1[id].prop2;
        T1[right].prop2+=T1[id].prop2;

        T1[left].sum+=(mid-l+1)*T1[id].prop2;
        T1[right].sum+=(r-mid)*T1[id].prop2;

        T1[left].upd2_time=T1[id].upd2_time;
        T1[right].upd2_time=T1[id].upd2_time;

        T1[left].upd2=1;
        T1[right].upd2=1;

        T1[id].prop2=0;
        T1[id].upd2=0;
        }
        else
        {
            /*
            T1[id].sum+=(r-l+1)*T1[id].prop2;
            T1[id].prop2=0;
            T1[id].upd2=0;
            */

        }

    }
    else
    {
        if(l!=r)
        {
        T1[left].prop3=T1[id].prop3;
        T1[right].prop3=T1[id].prop3;

        T1[left].sum=(mid-l+1)*T1[id].prop3;
        T1[right].sum=(r-mid)*T1[id].prop3;

        T1[left].upd3_time=T1[id].upd3_time;
        T1[right].upd3_time=T1[id].upd3_time;

        T1[left].upd3=1;
        T1[right].upd3=1;

        T1[id].prop3=0;
        T1[id].upd3=0;


        /***Clearing other propagation */




        T1[id*2].prop2=0;
        T1[id*2].prop1=0;
        T1[id*2+1].prop2=0;
        T1[id*2+1].prop1=0;

        T1[left].upd1=T1[right].upd1=1;
        T1[left].upd2=T1[right].upd2=1;

        T1[left].upd1_time=T1[id].upd3_time;
          T1[left].upd2_time=T1[id].upd3_time;

        T1[right].upd1_time=T1[id].upd3_time;
          T1[right].upd2_time=T1[id].upd3_time;
        }
        else
        {
           /* T1[id].sum=T1[id].prop3;
            T1[id].prop3=0;
            T1[id].upd3=0;
            */
        }
    }

}


void topdown_update(int id,int l,int mid,int r)
{
       if(T1[id].upd3)
    {
        update_child(id,l,mid,r,3);
    }


        if(T1[id].upd1 && T1[id].upd1_time>=T1[id].upd3_time)
    {
        update_child(id,l,mid,r,1);
    }

    if(T1[id].upd2 && T1[id].upd2_time>=T1[id].upd3_time)
    {
        update_child(id,l,mid,r,2);
    }

}


long long lazy_query(int id,int l,int r,int x,int y)
{
     if(l>y || r<x)
        return 0;


     int mid=(l+r)/2;
     topdown_update(id,l,mid,r);

     // cout<<"left= "<<l<<" right= "<<r<<" sum ="<<T1[id].sum<<endl;

    if(l>=x && r<=y)
    {
       //cout<<"left= "<<l<<" right= "<<r<<" sum ="<<T1[id].sum<<endl;
       //cout<<T1[id].prop1<<" "<<T1[id].prop2<<" "<<T1[id].prop3<<endl;

        return T1[id].sum;
    }


     mid=(l+r)/2;
     topdown_update(id,l,mid,r);

    long long p1=lazy_query(2*id,l,mid,x,y);
    long long p2=lazy_query(2*id+1,mid+1,r,x,y);



    return p1+p2;


}


int A[Max+1];

void lazy_init(int id,int l,int r)
{
    if(l==r)
    {
        T1[id].sum=0;

        T1[id].prop1=0;
        T1[id].upd1=0;

        T1[id].prop2=0;
        T1[id].upd2=0;

        T1[id].prop3=0;
        T1[id].upd3=0;

        T1[id].upd1_time=0;
        T1[id].upd2_time=0;
        T1[id].upd3_time=0;

        return;
    }

    int mid=(l+r)/2;

    lazy_init(2*id,l,mid);
    lazy_init(2*id+1,mid+1,r);

     T1[id].sum=T1[2*id].sum+T1[2*id+1].sum;

     T1[id].prop1=0;
     T1[id].upd1=0;

      T1[id].upd1_time=0;
      T1[id].upd2_time=0;
      T1[id].upd3_time=0;

     T1[id].prop2=0;
     T1[id].upd2=0;

     T1[id].prop3=0;
     T1[id].upd3=0;

}



void lazy_update1(int id,int l,int r,int x,int y, int val)
{

    if(l>y || r<x)
        return;

     int mid=(l+r)/2;
     topdown_update(id,l,mid,r);

    if(l>=x && r<=y)
    {
        T1[id].sum+=get_range_sum(l,r)*val;
        T1[id].upd1=1;
        T1[id].prop1+=val;
        T1[id].upd1_time=tim;

        return;
    }



    topdown_update(id,l,mid,r);



    lazy_update1(2*id,l,mid,x,y,val);
    lazy_update1(2*id+1,mid+1,r,x,y,val);

    T1[id].sum=T1[2*id].sum+T1[2*id+1].sum;

}



void lazy_update2(int id,int l,int r,int x,int y, int val)
{

    if(l>y || r<x)
        return;

    int mid=(l+r)/2;
    topdown_update(id,l,mid,r);

    if(l>=x && r<=y)
    {
        T1[id].sum+=(r-l+1)*val;
        T1[id].upd2=1;
        T1[id].prop2+=val;
        T1[id].upd2_time=tim;

        return;
    }

    topdown_update(id,l,mid,r);

    lazy_update2(2*id,l,mid,x,y,val);
    lazy_update2(2*id+1,mid+1,r,x,y,val);

    T1[id].sum=T1[2*id].sum+T1[2*id+1].sum;

}


void lazy_update3(int id,int l,int r,int x,int y, int val)
{

    if(l>y || r<x)
        return;

    int mid=(l+r)/2;
    topdown_update(id,l,mid,r);


    if(l>=x && r<=y)
    {
        T1[id].sum=(r-l+1)*val;
        T1[id].upd3=1;
        T1[id].prop3=val;
        T1[id].upd3_time=tim;

        return;
    }

    //int mid=(l+r)/2;
    topdown_update(id,l,mid,r);


    lazy_update3(2*id,l,mid,x,y,val);
    lazy_update3(2*id+1,mid+1,r,x,y,val);

    T1[id].sum=T1[2*id].sum+T1[2*id+1].sum;

}







int main()
{
    // freopen("input.txt","r",stdin);
    int tc;
    scani(tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {
        tim=0;
        int n;
        scani(n);

        printf("Case %d:\n",cs);

        lazy_init(1,1,Max-2);

        for(int p=1; p<=n ; p++)
        {
            tim++;
            int a,b;
            char ch;
            getchar();
            scanf("%c",&ch);

            if(ch=='A')
            {
                int a,b;
                scani(a);
                scani(b);

                lazy_update1(1,1,Max-2,a,b,1);

                lazy_update2(1,1,Max-2,a,b,1-a);

            }
            else if(ch=='B')
            {
                int a,b;
                scani(a);
                scani(b);

                lazy_update1(1,1,Max-2,a,b,-1);

                lazy_update2(1,1,Max-2,a,b,b+1);

            }
            else if(ch=='C')
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                lazy_update3(1,1,Max-2,a,b,c);
            }
            else
            {
                int a,b;
                scani(a);
                scani(b);

                long long res=lazy_query(1,1,Max-2,a,b);
                printf("%lld\n",res);

            }

        }

        for(int i=0 ;i<=4*Max ; i++)
        {
            T1[i].sum=0;
            T1[i].prop1=T1[i].prop2=T1[i].prop3=0;
            T1[i].upd1=T1[i].upd2=T1[i].upd3=0;
            T1[i].upd1_time=T1[i].upd2_time=T1[i].upd3_time=0;
        }
    }


    return 0;
}

