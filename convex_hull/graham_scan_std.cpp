#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct point{ ll x; ll y;};
point p0;
point base;

point arr[100100];
int N;

vector<point>hull;

long long distSq(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: -1; // clock or counterclock wise
}

bool comp(point p1,point p2)
{
   int o = orientation(p0,p1,p2);
   /****** non coliner case
    if (o == 0)
    {
           return (distSq(p0, p1) < distSq(p0, p2));
    }
    ******/

   if (o == 0)
   {
       if(p1.x>p0.x)
       {
            return (distSq(p0, p1) <= distSq(p0, p2));
       }
       else
       {
           return (distSq(p0, p1) > distSq(p0, p2));
       }
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

    /*
    for(int i=0; i<N ; i++)
    {
        printf("%lld %lld\n",arr[i].x,arr[i].y);
    }*/
    hull.clear();

    hull.push_back(arr[0]);
    hull.push_back(arr[1]);

    for(int i=2; i<N; i++)
    {
        int sz=hull.size();

        if(orientation(hull[sz-2],hull[sz-1],arr[i])<=0)
        {
            hull.push_back(arr[i]);
        }
        else
        {

            while(1)
            {
                hull.pop_back();
                sz=hull.size();
                if(orientation(hull[sz-2],hull[sz-1],arr[i])<=0)
                {
                    hull.push_back(arr[i]);
                    break;
                }

            }
        }
    }
    int sz=hull.size();
    for(int i=0; i<sz; i++)
        cout<<hull[i].x<<"  "<<hull[i].y<<endl;






}

int main()
{

    freopen("input.txt","r",stdin);

    scanf("%d",&N);

    for(int i=0; i<N ; i++)
        scanf("%lld %lld",&arr[i].x,&arr[i].y);

    graham_scan();




    return 0;
}
