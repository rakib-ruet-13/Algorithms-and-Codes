#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    int x1,y1,a1,b1,a2,b2,m1,m2,n1,n2;

    while(cin>>x1>>y1>>a1>>b1>>a2>>b2)
    {

        m1=a1+a2;
        n1=b1+b2;

        m2=a1+b2;
        n2=a2+b1;

        if(x1<y1)
            swap(x1,y1);
        /*if(m1<n1)
            swap(m1,n1);
        if(m2<n2);
        swap(m2,n2);*/

        /*cout<<m1<<n1<<m2<<n2<<endl;
        cout<<x1<<y1<<endl;*/

        if( (m1<=x1 && max(b1,b2)<=y1) || (m1<=y1 && max(b1,b2)<=x1) ||(n1<=y1 && max(a1,a2)<=x1)||  (n1<=x1 && max(a1,a2)<=y1) || (m2<=x1 && max(a2,b1)<=y1) || (m2<=y1 && max(a2,b1)<=x1) || (n2<=y1 && max(a1,b2)<=x1)|| (n2<=x1 && max(a1,b2)<=y1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;



    }
    return 0;
}
