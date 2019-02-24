#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    long int t,S,q,cnt;
    double s,r;

    while(cin>>t>>S>>q)
    {
        cnt=1;
        s=S;
        r=(double)(q-1)/(double)q;
        s=s+s*s*(1-pow(r,r)/(1-r));
        while((long int)s<t)
        {
            cnt++;
            s=s+s*s*(1-pow(r,r)/(1-r));

            cout<<s<<endl;
        }
        cout<<cnt<<endl;
    }


}
