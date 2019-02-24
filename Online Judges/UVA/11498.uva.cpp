#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long int tc,x,y,x1,y1;

    while(cin>>tc && tc!=0)
    {
        cin>>x>>y;
        for(int i=0;i<tc;i++)
        {
            cin>>x1>>y1;

            if(x1==x || y1==y)
                cout<<"divisa";
            else if(x1>x && y1>y)
                cout<<"NE";
            else if(y1>y && x1<x)
                cout<<"NO";
            else if(x1>x && y1<y)
                cout<<"SE";
            else
                cout<<"SO";
            cout<<endl;

        }

    }
    return 0;
}
