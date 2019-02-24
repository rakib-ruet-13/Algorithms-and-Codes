#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pi acos(-1.0000000000)

struct point{ ll x; ll y;};
point p0;
point base;

point arr[200100];
int N;

vector<point>hull;

long long distSq(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}


double distSq2(point p1, point p2)
{
    return ((double)p1.x - (double)p2.x)*((double)p1.x - (double)p2.x) +
          ((double)p1.y - (double)p2.y)*((double)p1.y - (double)p2.y);
}

long long orientation(point p, point q, point r)
{
    long long val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: -1; // clock or counterclock wise
}

bool comp(point p1,point p2)
{
   int o = orientation(p0,p1,p2);

   if(o==0)
   {
     return (distSq(p0, p1) < distSq(p0, p2));
   }

   return (o == 1)? 0 :1;
}



void select_base_point()
{
    int loc=0;
    point temp=arr[0];
    for(int i=0; i<N ; i++)
    {
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

    for(int i=2; i<N; i++)
    {
        int sz=hull.size();



        if(orientation(hull[sz-2],hull[sz-1],arr[i])<0)
        {
            hull.push_back(arr[i]);
        }
        else
        {
            //cout<<"i== "<<i<<endl;

            while(1)
            {
                sz=hull.size();
                 if(sz==1)
                 {
                    hull.push_back(arr[i]);
                    break;
                 }

                hull.pop_back();
                sz=hull.size();

                if(sz>1)
                {

                    if(orientation(hull[sz-2],hull[sz-1],arr[i])<0 )
                    {
                        hull.push_back(arr[i]);
                        break;
                    }

                }

            }
        }
    }


    /***

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

    **/


}

int main()
{

    //freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);

    double d;

    for(int cs=1 ; cs<= tc ; cs++)
    {

    scanf("%d %lf",&N,&d);

    for(int i=0; i<N ; i++)
        scanf("%lld %lld",&arr[i].x,&arr[i].y);

    double per=0;


    if(N>2)
    graham_scan();


    if(N==1)
    {
        per= 2*pi*d;

    }
    else if(N==2)
    {
        per=2*sqrt(abs(distSq(arr[0],arr[1])));
        per+=2*pi*d;
    }
    else
    {
        int sz=hull.size();

        if(sz==2)
        {
            per=2*sqrt(abs(distSq(hull[0],hull[1])));
            per+=2*pi*d;

        }
        else
        {
            double dis=0;

            for(int i=1; i<sz; i++)
            {
                dis+=sqrt(distSq(hull[i],hull[i-1]));
            }
            dis+=sqrt(distSq(hull[0],hull[sz-1]));

            per=2*pi*d;
            per+=dis;
        }

    }

    printf("Case %d: %.10f\n",cs,per);
    }

    return 0;
}



