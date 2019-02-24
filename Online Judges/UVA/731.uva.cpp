#include<iostream>
using namespace std;
int main()
{
    long long int l,u,temp,m,i,j,cnt,tt;
    while(cin>>l>>u && l && u )
    {

        if(u<l)
        {
            tt=u;
            u=l;
            l=tt;
        }


        m=0;
        for(i=l;i<=u;i++)
        {
            j=i;
            cnt=0;
            do
            {
                if(j%2==0)
                    j=j/2;
                else
                    j=3*j+1;
                cnt++;
            }
            while(j!=1);
            {
                if(cnt>m)
                {
                    temp=i;
                    m=cnt;
                }
            }
        }
        cout<<"Between "<<l<<" and "<<u;
     cout<<", "<<temp<<" generates the longest sequence of "<<m<<" values."<<endl;
    }
    return 0;
}
