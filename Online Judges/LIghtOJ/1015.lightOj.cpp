#include<iostream>
using namespace std;

int main()
{
    long long int tc,num,sum,dust,i,j;
    cin>>tc;

    for(i=1;i<=tc;i++)
    {
        cin>>num;
        sum=0;
        for(j=1;j<=num;j++)
        {
            cin>>dust;
            if(dust>0 && dust<100)
                sum=sum+dust;
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }
    return 0;

}
