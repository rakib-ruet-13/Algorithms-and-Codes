#include<iostream>
using namespace std;
int main()
{
    long long int r,sum,num,cs=1,i;
    while(cin>>r>>num && r &&num)
    {
        cout<<"Case "<<cs++<<": ";
        sum=num;
        i=0;
        if(sum+num*26<r)
            cout<<"impossible"<<endl;
            else
            {
                if(sum>=r)
                    i=0;
                else
                {
                    do
                    {
                        sum=sum+num;
                        i++;
                    }
                        while(sum<r);
                }
                cout<<i<<endl;
            }
    }
    return 0;
}
