#include<bits/stdc++.h>

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
#define printi(a) printf("%d\n",&a);
#define uu first
#define vv second

ll gcd(ll a,ll b){ if(a%b==0) return b; else return gcd(b,a%b);}
ll power(ll b,ll p) { ll res=1; for(ll i=1; i<=p ;i++)res*=b; return res;}
ll bigmod(ll n, ll p, ll m)
{if(p==0)return 1; if(p%2==0){ ll temp=bigmod(n,p/2,m);return (temp%temp)%m;}
else{return (n*bigmod(n,p-1,m))%m;}}

struct node
{
    ll ind;
    ll val;
};

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);

    int tc;
    scani(tc);

    ll mat[101][101];

    rep(cs,1,tc)
    {
        ll res=-111111;

        int row,col;
        scani(row);
        scani(col);

        rep(i,1,row)
        {
            rep(j,1,col)
            {
                scan(mat[i][j]);

                 // print(mat[i][j]);
            }


        }

        rep(i,1,row)
        {
            vector<node>vct;
            rep(j,1,col)
            {
                ll sum=0;
                for(int k=i; k>0 ; k--)
                {
                    if(mat[k][j]==1)
                        sum++;
                    else
                        break;
                }
                node temp;
                temp.ind=j;
                temp.val=sum;

                vct.push_back(temp);

            }


            node a;
            a.ind=col+1;
            a.val=0;
            vct.push_back(a);

            stack<node>stk;
            while(!stk.empty())stk.pop();


           // cout<<"row "<<i<<endl;
            for(int p=0; p<vct.size() ; p++)
            {

               // cout<<vct[p].ind<<" "<<vct[p].val<<endl;

                if(stk.empty())
                    stk.push(vct[p]);
                else
                {
                    bool flag=1;
                    node t;

                    while(1)
                    {

                    if(stk.empty())
                    {
                         if(!flag)
                        {
                           vct[p].ind=t.ind;
                        }

                        stk.push(vct[p]);
                        break;

                    }

                     t=stk.top();



                    if(t.val<vct[p].val)
                    {
                        if(!flag)
                        {
                           vct[p].ind=t.ind;
                        }

                        stk.push(vct[p]);
                        break;

                    }
                    else
                    {
                        //cout<<"RES "<< t.val<<" "<<t.ind<<" "<<vct[p].ind<<endl;
                        res=max(res,t.val*(vct[p].ind-t.ind));
                        stk.pop();
                        flag=0;
                    }


                    }


                }
            }


            vct.clear();
        }

        printf("Case %d: ",cs);

        print(res);

    }
    return 0;
}
