#include<iostream>
using namespace std;

int main()
{
    long long int tc,cs=0,num;

    cin>>tc;
    while(tc--)
    {
        int flag=0;

        for(int i=0;i<3;i++)
        {
            cin>>num;
            if(num>20)
                flag=1;
        }

        cout<<"Case "<<++cs<<": ";

        if(flag==1)
            cout<<"bad"<<endl;
        else
            cout<<"good"<<endl;
    }


}
