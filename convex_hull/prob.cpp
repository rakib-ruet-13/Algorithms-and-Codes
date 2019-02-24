#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct point{ ll x; ll y;};
point p0;
point base;

point arr[400100];
int N;

vector<point>hull;

long long distSq(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(point p, point q, point r)
{
    long long  val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: -1; // clock or counterclock wise
}

bool comp(point p1,point p2)
{
   int o = orientation(p0,p1,p2);
   if (o == 0)
   {

       /****normal case big distance comes first ****/
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
                if(orientation(hull[sz-2],hull[sz-1],arr[i])<=0 || sz==2)
                {
                    hull.push_back(arr[i]);
                    break;
                }

            }
        }
    }

    //for(int i=0; i<hull.size() ; i++)
        //cout<<hull[i].x<<" "<<hull[i].y<<endl;
}

vector<point>A,B;


bool comp1(point a,point b)
{

    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{

    //freopen("input.txt","r",stdin);

    //scanf("%d",&N);

    int n,m;
    scanf("%d %d",&n,&m);

    point temp;

    int k=0;
    for(int i=0; i<n; i++)
    {
        scanf("%lld %lld",&temp.x,&temp.y);
        arr[k++]=temp;
        A.push_back(temp);

    }

      for(int i=0; i<m; i++)
    {
        scanf("%lld %lld",&temp.x,&temp.y);
          arr[k++]=temp;
          B.push_back(temp);

    }
    N=k;
    graham_scan();

    sort(A.begin(),A.end(),comp1);
      sort(B.begin(),B.end(),comp1);
        sort(hull.begin(),hull.end(),comp1);



    bool flag=0;

    if(hull.size()==A.size())
    {
        int fl=1;
        for(int i=0; i<hull.size() ; i++)
        {
            if(hull[i].x==A[i].x && hull[i].y==A[i].y)
            {

            }
            else
            {
                fl=0;
                break;
            }
        }
        if(fl==1)
            flag=1;

    }

      if(hull.size()==B.size())
    {
        int fl=1;
        for(int i=0; i<hull.size() ; i++)
        {
            if(hull[i].x==B[i].x && hull[i].y==B[i].y)
            {

            }
            else
            {
                fl=0;
                break;
            }
        }
        if(fl==1)
            flag=1;

    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;




    return 0;
}

