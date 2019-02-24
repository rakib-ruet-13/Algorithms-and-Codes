#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b ;i++)
#define pb push_back
#define read64(x) scanf("%lld",&x)
#define read32(x) scanf("%d",&x)

#define mod 1e9+7
#define pi acos(-1.000)
#define Max 1010

using namespace std;

double l,w;
double len,wid;

double area(double x);

double bs(double ll,double ul)
{
    double mid=(ll+ul)/2;

    if(fabs(area(ll)-area(ul))<.00000001)
        return area(mid);

    if(area(mid)>area(ll))
    {
        return bs(mid,ul);
    }
    else
        return bs(ll,mid);
}


double area(double x)
{
    return x*(len-2*x)*(wid-2*x);
}

int main()
{

    int tc;

    read32(tc);

    rep(cs,1,tc)
    {

        scanf("%lf %lf",&l,&w);

        double  pre=0;
        double  val=1;

        for(int x=1; 2.00*(double)x<w && 2.00*(double)w<l ; x++ )
        {
            if(x*(w-2*x)*(l-2*x)>pre)
            {
                 val=x;
                 pre=x*(w-2*x)*(l-2*x);
            }
        }

        len=l;
        wid=w;

        double n;
        n=double(val);

        double res1=bs(n-1,n);

        //cout<<res1<<endl;



        double res2=bs(n,n+1);

         //cout<<res2<<endl;

        double res3=bs(0,w/2);

           // cout<<res3<<endl;

        res1=max(res1,res2);

        res1=max(res1,res3);

        printf("Case %d: %.10f\n",cs,res1);





    }
    return 0;

}
