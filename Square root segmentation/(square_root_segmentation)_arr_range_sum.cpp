#include<bits/stdc++.h>

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
typedef long long ll;
ll gcd(ll a,ll b){ if(a%b==0) return b; else return gcd(b,a%b);}
ll power(ll b,ll p) { ll res=1; for(ll i=1; i<=p ;i++)res*=b; return res;}
ll bigmod(ll n, ll p, ll m)
{if(p==0)return 1; if(p%2==0){ ll temp=bigmod(n,p/2,m);return (temp%temp)%m;}
else{return (n*bigmod(n,p-1,m))%m;}}



using namespace std;


/*** indexing method index 0**/
ll arr[10000];
ll seg_sum[101];
ll seg_prop[101];
ll k;

void square_root_seq_init(ll n)
{
   // for(int i=0 ; i<=n ;i++)
       // arr[i]=0;
    for(int i=0; i<= sqrt(n) ; i++)
    {
        seg_sum[i]=seg_prop[i]=0;
    }

    k=sqrt(n);

    for(int i=0; i<n ; i++)
    {
        seg_sum[i/k]+=arr[i];
    }
}

void square_root_seq_update(ll ind,ll val)
{
    arr[ind]+=val;
    seg_sum[ind/k]+=val;
}

void square_root_seq_range_update(ll lo,ll hi,ll val)
{
     ll x, y;

    if(lo>hi)
        swap(lo,hi);

    x=(lo/k);
    y=(hi/k);

    long long p1,p2;

    if(x==y)
    {

        for(int i=lo; i<=hi ; i++)
            arr[i]+=val;

        seg_sum[x]+=val*(hi-lo+1);
    }
    else
    {
         p1=k*(x+1)-1;
         p2=k*y;



         for(int i=lo ; i<=p1 ; i++)
         {
             arr[i]+=val;
              seg_sum[x]+=val;
         }


           for(int i=p2 ; i<=hi ; i++)
         {
            arr[i]+=val;
             seg_sum[y]+=val;
         }


         for(int i=x+1 ; i<=y-1 ; i++)
         {
             seg_prop[i]+=val;
         }

    }

}

ll square_root_seg_query(ll lo, ll hi)
{


    ll n;

    ll x, y;

    if(lo>hi)
        swap(lo,hi);

    x=(lo/k);
    y=(hi/k);

    long long p1,p2;

    if(x==y)
    {
        ll sum=0;
        for(int i=lo; i<=hi ; i++)
            sum+=arr[i];
        sum+=seg_prop[x]*(hi-lo+1);

        return sum;
    }
    else
    {
         p1=k*(x+1)-1;
         p2=k*y;

         ll sum1=0;
         ll sum2=0;
         ll sum3=0;

         for(int i=lo ; i<=p1 ; i++)
         {
             sum1+=arr[i];
         }

         sum1+=seg_prop[x]*(p1-lo+1);


           for(int i=p2 ; i<=hi ; i++)
         {
             sum2+=arr[i];
         }

         sum2+=seg_prop[y]*(hi-p2+1);

         for(int i=x+1 ; i<=y-1 ; i++)
         {
             sum3+= seg_sum[i]+ k*seg_prop[i];
         }

         return sum1+sum2+sum3;

    }

}


int main()
{
    int tc;
    scani(tc);

    rep(cs,1,tc)
    {
        ll n;
        scan(n);
        rep(i,0,n-1)
         scan(arr[i]);

        square_root_seq_init(n);

        int q;
        scani(q);

        while(q)
        {
            int qtype;
            scani(qtype);

            if(qtype==1)
            {
                //query
                ll lo, hi;
                scan(lo);
                scan(hi);
                print(square_root_seg_query(lo,hi));
            }
             if(qtype==2)
            {
                //update single ele
                ll ind,val;
                scan(ind);
                scan(val);
                square_root_seq_update(ind,val);

            }
             if(qtype==3)
            {
                //range update
                ll lo,hi,val;
                scan(lo);
                scan(hi);
                scan(val);
                square_root_seq_range_update(lo,hi,val);

            }

        }

    }
    return 0;
}


