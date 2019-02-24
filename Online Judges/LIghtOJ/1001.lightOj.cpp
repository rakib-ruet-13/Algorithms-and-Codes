#include<iostream>
using namespace std;

int main()
{
    int tc,num,i;
    cin>>tc;
    {
        for(i=1;i<=tc;i++)
        {
            cin>>num;
            if(num>10)

                cout<<10<<" "<<num-10<<endl;
            else
                cout<<num<<" "<<0<<endl;
        }
    }
    return 0;

}
