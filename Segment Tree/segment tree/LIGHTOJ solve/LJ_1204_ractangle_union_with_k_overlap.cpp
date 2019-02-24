#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 60010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair

using namespace std;

struct cord
{
    int x, y1, y2, val; //val for starting or ending
    cord(int _x=0, int _y1=0, int _y2=0, int _val=0)
    {
        x=_x, y1=_y1, y2=_y2, val=_val;
    }
};
cord pnt[MAX];
int ans[4*MAX], upd[4*MAX];
vector<int>y;

bool cmp(cord a, cord b)
{
    if(a.x==b.x) return (a.val > b.val);
    return (a.x < b.x);
}
int k;

int update(int node, int st, int end, int i, int j, int val)
{
    if(j<=y[st] || i>=y[end]) return ans[node];
    if(y[st]>=i && y[end]<=j)
    {
        upd[node]+=val;
        if(upd[node]>=k)
            return ans[node] = y[end]-y[st];
        else
        {
            if(end-st==1)
                return ans[node]=0;
            int mid=(st+end)>>1, ret1, ret2;
            if(upd[node]==k-1&&val==-1) upd[2*node]++;
            if(upd[node]==k-1&&val==-1) upd[2*node+1]++;
            ret1 = update(2*node, st, mid, i, j, val);
            ret2 = update(2*node+1, mid, end, i, j, val);
            return ans[node] = ret1+ret2;
        }
    }

    int mid=(st+end)>>1, ret1, ret2;
    ret1 = update(2*node, st, mid, i, j, val);
    ret2 = update(2*node+1, mid, end, i, j, val); //special attention to mid
    if(upd[node]<k) ans[node] = ret1+ret2;
    else ans[node]=y[end]-y[st];
    return ans[node];
}


int main()
{
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        y.clear();
        int i, j, n, x1, y1, x2, y2, cnt=0, m;
        scanf("%d %d", &n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1--;
            y1--;
            pnt[cnt++] = cord(x1, y1, y2, 1);
            pnt[cnt++] = cord(x2, y1, y2, -1);
            y.pb(y1), y.pb(y2);
        }
        sort(y.begin(), y.end());
        y.resize(unique(y.begin(), y.end())-y.begin());
        n = SZ(y);
        sort(&pnt[0], &pnt[0]+cnt, cmp);
        memset(ans, 0, sizeof ans); memset(upd, 0, sizeof upd);

        ll sum=0, now; x1=-1;
        for(i=0;i<cnt;i++)
        {
            x2 = pnt[i].x;
            now = x2-x1;
            sum+=now*ans[1];
            //print2(pnt[i].y1,pnt[i].y2);
            update(1, 0, n-1, pnt[i].y1, pnt[i].y2, pnt[i].val);
            x1 = x2;
        }
        csprnt;
        printf("%lld\n", sum);
    }
    return 0;
}

