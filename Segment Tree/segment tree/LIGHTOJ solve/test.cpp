
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>


# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)

#define EPS 1e-11
#define inf ( 1LL << 31 ) - 1
#define LL long long

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))

# define VI vector<int>
# define VS vector<string>
# define VC vector<char>

#define mp make_pair
#define pb push_back
#define sz(k) (int)(k).size()
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define pii pair<int,int>

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;


using namespace std;

#define MAX 250005

struct data {
    LL a,b;
    bool c;
    LL d,sum;
    LL x;
} tree [5*MAX];
LL sum(int n)
{
    if (n == 0) return 0;
    LL s = n;
    s *= n + 1;
    s /= 2;
    return s;
}


void push(int node,int left,int right) {
    if(!tree[node].a && !tree[node].b && !tree[node].c) {
        return;
    }
    LL item= (right-left+1);
    if(tree[node].c) {
        tree[node].sum= item * tree[node].x;
    }
    tree[node].sum += item * tree[node].d;
    tree[node].sum += sum(item) * (tree[node].a + tree[node].b);

    if(left!=right) {
        int lt = 2*node, rt = lt + 1, mid = (left+right)/2;
        if(tree[node].c) {
            tree[lt].a=tree[lt].b=tree[lt].d=0;
            tree[rt].a=tree[rt].b=tree[rt].d=0;

            tree[lt].x=tree[rt].x=tree[node].x;
            tree[lt].c=tree[rt].c=1;
        }
        tree[lt].a+=tree[node].a;
        tree[lt].b+=tree[node].b;

        tree[rt].a+=tree[node].a;
        tree[rt].b+=tree[node].b;

        LL delta = mid + 1 - left;
        delta *= tree[node].a;
        tree[rt].d += tree[node].d + delta;

        delta = right - mid;
        delta *= tree[node].b;
        tree[lt].d += tree[node].d + delta;
    }

    tree[node].a=tree[node].b=tree[node].c=0;
    tree[node].x=0;
    tree[node].d=0;
    return;
}

void updateA(int node,int left,int right,int i,int j) {
    push(node,left,right);
    if(left > j || right <i) return;
    if(left >= i && right <=j) {
        tree[node].sum += sum(right-i+1)-sum(left-i);

        int lt=2*node, rt=2*node+1;

        tree[lt].a++;
        tree[rt].a++;
        int mid=(left+right)>>1;
        tree[lt].d += left - i;
        tree[rt].d += mid-i+1;

        return;
    }
    int mid=(left+right)>>1;
    updateA(2*node,left,mid,i,j);
    updateA(2*node+1,mid+1,right,i,j);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    return;
}


void updateB(int node,int left,int right,int i,int j) {
    push(node,left,right);
    if(left > j || right <i) return;
    if(left >= i && right <=j) {
        tree[node].sum += sum(j-left+1)-sum(j-right);

        int lt=2*node, rt=2*node+1;

        tree[lt].b++;
        tree[rt].b++;
        int mid=(left+right)>>1;
        tree[lt].d += j - mid;
        tree[rt].d += j - right;

        return;
    }
    int mid=(left+right)>>1;
    updateB(2*node,left,mid,i,j);
    updateB(2*node+1,mid+1,right,i,j);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    return;
}

void updateC(int node,int left,int right,int i,int j,LL v) {
    push(node,left,right);
    if(left > j || right < i) return;
    if(left>= i && right<=j) {
        LL item=(right-left+1);
        tree[node].sum= item*v;
        int lt=2*node, rt=2*node+1;
        tree[lt].a=tree[lt].b=0;
        tree[rt].a=tree[rt].b=0;
        tree[lt].d=tree[rt].d=0;

        tree[lt].c=tree[rt].c=1;
        tree[lt].x=tree[rt].x=v;
        return;
    }
    int mid=(left+right)>>1;
    updateC(2*node,left,mid,i,j,v);
    updateC(2*node+1,mid+1,right,i,j,v);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    return;
}


LL query(int node,int left,int right,int i,int j){
    push(node,left,right);
    if(left > j || right <i) return 0;

    if(left>=i && right<=j){
        return tree[node].sum;
    }
    int mid=(left+right)>>1;

    LL sm= query(2*node,left,mid,i,j);
    sm+= query(2*node+1,mid+1,right,i,j);
    return sm;
}

int main() {
    LL t,chk=1,n,x,y,v;
    char c;
    scanf("%lld",&t);
    while(t--)
    {
        printf("Case %lld:\n",chk++);
        ms(tree,0);
        scanf("%lld",&n);
        while(n--)
        {
            scanf(" %c",&c);
            if(c=='A')
            {
                scanf("%lld %lld",&x,&y);
                updateA(1,0,MAX,x,y);
            }
            if(c=='B')
            {
                scanf("%lld %lld",&x,&y);
                updateB(1,0,MAX,x,y);
            }
            if(c=='C')
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                updateC(1,0,MAX,x,y,v);
            }
            if(c=='S')
            {
                scanf("%lld %lld",&x,&y);
                printf("%lld\n",query(1,0,MAX,x,y));
            }
        }
   }
    return 0;
}

