#include <bits/stdc++.h>
#define ll long long
#define sl(n) scanf("%lld", &n)
#define lf double
#define sf(n) scanf("%lf", &n)
#define pb push_back

using namespace std;


ll arr[2][3000100], val[3000100], tree[2][6000000];
map <ll, ll> mp1, mp2, c1, c2, mp, wr;

void build( ll node , ll a , ll b, ll t )
{

    if( a == b )
    {
        tree[t][node] = arr[t][a];
        return;
    }

    ll left , right, mid;
    left = node*2 ;
    right  = left + 1 ;
    mid= (a+b)/2;

    build( left , a, mid, t );
    build( right , mid+1 , b, t );
    tree[t][node] = max( tree[t][left], tree[t][right] );


}

ll query( ll node , ll a, ll b, ll i , ll j, ll t )
{

    if( i>b || j<a ) return 0;
    if( i<=a && b<=j ) return tree[t][node];
    ll left , right, mid;
    left = node*2 ;
    right  = left + 1 ;
    mid= (a+b)/2;

    ll r1 = query( left , a, mid , i, j , t );
    ll r2 = query(right,mid+1,b,i,j,t);
    return max( r1,r2 );


}


int main()
{

    ll n, i, j, v=0, x, a, b, ans=0, ww, p;
    sl(n);
    for(i=1; i<=n; i++)
    {
        sl(arr[0][i]);

        mp1[arr[0][i]]=1;

        if(mp[arr[0][i]]==0)
        {
            mp[arr[0][i]]=1;
            val[v]=arr[0][i];
            v++;
        }

    }
    //cout<<mp2[7]<<endl;


    for(i=1; i<=n; i++)
    {
        sl(arr[1][i]);

        if(mp[arr[1][i]]==0)
        {
            mp[arr[1][i]]=1;
            val[v]=arr[1][i];
            v++;
        }

        if(mp1[arr[1][i]]==1)
        {
            mp2[arr[1][i]]=1;
        }
    }
    //cout<<mp2[7]<<endl;

    for(i=1; i<=n; i++)
    {
        if(mp2[arr[0][i]]!=1)
        {
            wr[arr[0][i]]=1;
            if(c1[arr[0][i]]==0)
            {
                c1[arr[0][i]]=i;
            }
            else
            {
                c2[arr[0][i]]=i;
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        if(mp2[arr[1][i]]!=1)
        {
            wr[arr[1][i]]=2;
            if(c1[arr[1][i]]==0)
            {
                c1[arr[1][i]]=i;
            }
            else
            {
                c2[arr[1][i]]=i;
            }
        }
    }

    sort(val, val+v);
    build(1, 1, n, 1);
    build(1, 1, n, 0);
    //cout<<v<<endl;

    for(i=v-1; i>=0; i--)
    {
        x = val[i];
        //cout<<x<<endl;

        if(mp2[x]==1)
        {
            //cout<<"P "<<x<<endl;
            ans = max(x, ans);
            break;
        }
        else
        {
           // cout<<"NNN"<<endl;
            ww = wr[x];
            ww--;
            //printf("%lld %lld %lld\n", x, c1[x], c2[x]);
            if(c1[x]==c2[x]-1)
                continue;
            else
            {
                a = c1[x];
                b = c2[x];
                p = query(1, 1, n, a+1, b-1, ww);
                //cout<<p<<endl;
                if(p>x)
                    ans = max(ans, x);
                else
                    ans = max(ans, p);

            }
        }
    }

    printf("%lld\n", ans);




    return 0;
}



