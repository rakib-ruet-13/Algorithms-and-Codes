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


}

int main()
{

    //freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {

    scanf("%d",&N);

    for(int i=0; i<N ; i++)
        scanf("%lld %lld",&arr[i].x,&arr[i].y);

    graham_scan();

    point a,b,c;

    double theta=180;

    if(hull.size()<3)
        theta=0;
    else
    {

    for(int i=0; i<hull.size() ; i++)
    {
        if(i==0)
        {
            a=hull[hull.size()-1];
            b=hull[0];
            c=hull[1];

        }
        else if(i==hull.size()-1)
        {
            a=hull[i-1];
            b=hull[i];
            c=hull[0];
        }
        else
        {
            a=hull[i-1];
            b=hull[i];
            c=hull[i+1];
        }


        double bb=(double)distSq2(a,c);
        double cc=(double)distSq2(b,a);
        double aa=(double)distSq2(b,c);

        //cout<<sqrt(aa)<<"  "<<sqrt(bb)<<"  "<<sqrt(cc)<<endl;


        double temp=(double)aa+(double)cc-(double)bb;
        temp/=(2.000* sqrt(fabs((double)aa))*sqrt(fabs((double)cc)));



        temp=acos(temp);

        temp=temp*180/pi;
        //cout<<temp<<endl;

        theta=min(temp,theta);
    }




    }
    printf("Case %d: %.10f\n",cs,theta);




    }




    return 0;
}


