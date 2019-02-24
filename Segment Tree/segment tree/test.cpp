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
int arr[1000001];
vector<int> seg[1001];
vector<int> seg_sorted[1001];
int seg_prop[1001];

ll k;
int KK;

void square_root_seq_init(ll n)
{
   // for(int i=0 ; i<=n ;i++)
       // arr[i]=0;
    for(int i=0; i<= ceil(sqrt(n)) ; i++)
    {
        seg[i].clear();
        seg_prop[i]=0;
    }

    k=sqrt(n);

    for(int i=0; i<n ; i++)
    {
        seg[i/k].push_back(arr[i]);
        //cout<<i/k<<" "<<arr[i]<<endl;
    }

    for(int i=0; i<=n/k; i++)
    {
        seg_sorted[i].clear();

            for(int p=0; p<seg[i].size();p++)
           {

            seg_sorted[i].push_back(seg[i][p]);
           // cout<<seg[i][p];

           }

        sort(seg_sorted[i].begin(),seg_sorted[i].end());
    }
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


         p2=k*(x+1)-1;
         p1=k*y;

         seg_sorted[x].clear();

            for(int i=p1; i<=p2 ; i++)
             seg_sorted[x].push_back(arr[i]);


    }
    else
    {
         p1=k*(x+1)-1;
         p2=k*y;



         for(int i=lo ; i<=p1 ; i++)
         {
             arr[i]+=val;
         }

         seg_sorted[x].clear();

         int st=k*x;

         for(int i=st ; i<=p1 ; i++)
         {
             seg_sorted[x].push_back(arr[i]);
         }
         sort(seg_sorted[x].begin(),seg_sorted[x].end());




           for(int i=p2 ; i<=hi ; i++)
         {
            arr[i]+=val;

         }

          seg_sorted[y].clear();

         int ed=k*(y+1)-1;

         for(int i=p2 ; i<=ed ; i++)
         {
             seg_sorted[y].push_back(arr[i]);
         }
          sort(seg_sorted[y].begin(),seg_sorted[y].end());



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
    ll sum=0;

    if(x==y)
    {
        int tmp=KK;

        tmp-=seg_prop[x];


        for(int i=lo; i<=hi ; i++)
        {
            if(arr[i]>=tmp)
                sum++;

        }

        return sum;
    }
    else
    {
         p1=k*(x+1)-1;
         p2=k*y;

         ll sum1=0;
         ll sum2=0;
         ll sum3=0;


        int tmp=KK;
        tmp-=seg_prop[x];
         for(int i=lo ; i<=p1 ; i++)
         {
             if(arr[i]>=tmp)
               sum1++;
         }



        tmp=KK;
        tmp-=seg_prop[y];

           for(int i=p2 ; i<=hi ; i++)
         {
             if(arr[i]>=tmp)
                sum2++;
         }


         for(int i=x+1 ; i<=y-1 ; i++)
         {
            int tmp=KK;
            tmp-=seg_prop[i];

            sum3+=(seg_sorted[i].size()-(upper_bound(seg_sorted[i].begin(),seg_sorted[i].end(),tmp-1)-seg_sorted[i].begin()));
         }

         return sum1+sum2+sum3;

    }

}


int main()
{
   int n;
   scani(n);

   for(int i=0 ; i<n ;i++)
    scani(arr[i]);

   square_root_seq_init(n);

    int q;
    scani(q);

    while(q--)
    {
        int a;
        scani(a);



        if(a==1)
        {
            int x,y,k;
            scani(x);
            scani(y);
            scani(KK);

            cout<<square_root_seg_query(x-1,y-1);



        }
        else
        {
            int x,y;
            scani(x);
            scani(y);

            square_root_seq_range_update(x-1,y-1,1);


        }


    }


}






