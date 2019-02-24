#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point{ ll x; ll y; ll pos;};
point p0;
point base;

point arr[100100];
int N;
int cnt;


vector<point>hull;
long long distSq(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(point p, point q, point r)
{
    long long val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: -1; // clock or counterclock wise
}

bool comp(point p1,point p2)
{
   int o = orientation(p0,p1,p2);
   if (o == 0)
   {
        return (distSq(p0, p1) < distSq(p0, p2));
   }


   return (o == 1)? 0: 1;
}

void select_base_point()
{
    int loc=0;
    point temp=arr[0];
    for(int i=0; i<N ; i++)
    {
        //cout<<arr[i].x<<" "<<arr[i].y<<endl;
        if(arr[i].y<temp.y || (arr[i].y==temp.y &&  arr[i].x<temp.x))
        {
            loc=i;
            temp=arr[i];
        }

    }
    swap(arr[0],arr[loc]);
    base=arr[0];
    p0=arr[0];


}



void graham_scan()
{
    select_base_point();

    sort(arr+1,arr+N,comp);

    hull.clear();

    hull.push_back(arr[0]);
    hull.push_back(arr[1]);

    cnt=0;

    for(int i=2; i<N; i++)
    {
        hull.push_back(arr[i]);

        if(orientation(arr[0],arr[1],arr[i])==0)
            cnt++;
    }
    vector<point>vct;

    int sz=hull.size();

    vct.push_back(hull[sz-1]);
    hull.pop_back();

    sz=hull.size();

    int k=0;

    for(int i=sz-1; i>1 ;i--)
    {
        if(orientation(p0,vct[0],hull[i])==0)
                k++;
        else
            break;

    }

    while(k--)
    {
        point pp =hull.back();
        hull.pop_back();
        vct.push_back(pp);
    }


    for(int i=0; i<vct.size() ; i++)
    {
        hull.push_back(vct[i]);
    }
    vct.clear();
}



int main()
{

    //freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {

        scanf("%d",&N);

        for(long long i=0; i<N ; i++)
        {
            scanf("%lld %lld",&arr[i].x,&arr[i].y);
            arr[i].pos=i;
        }

        graham_scan();

        if(cnt < N-2)
        {
            printf("Case %d:\n",cs);
           for(int i=0; i<N; i++)
           {
               if(i!=0)
                printf(" %lld",hull[i].pos);
               else
                printf("%lld",hull[i].pos);

           }
           printf("\n");

        }
        else
        {
              printf("Case %d:\n",cs);
            printf("Impossible\n");
        }
        cnt=0;
        hull.clear();

    }


    return 0;
}




