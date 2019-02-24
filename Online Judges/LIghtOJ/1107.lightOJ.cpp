#include<iostream>
using namespace std;

int main()
{
    long long tc,x1,y1,x2,y2,n1,n2,num,cs=0;

    cin>>tc;
    while(tc--)
    {
      cin>>x1>>y1>>x2>>y2;
      if(x2<x1)
      {
          swap(x1,x2);

      }
      if(y2<y1)
        swap(y1,y2);
      cin>>num;
      cout<<"Case "<<++cs<<":"<<endl;
      for(int i=0;i<num;i++)
      {
          cin>>n1>>n2;
          if(x1<=n1 && n1<=x2 && y1<=n2 && n2<=y2)
            cout<<"Yes"<<endl;
          else
            cout<<"No"<<endl;
      }
    }

    return 0;
}
