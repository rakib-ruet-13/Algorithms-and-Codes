#include<iostream>
using namespace std;

int main()
{
    int age[10];
    int tc,num;
    cin>>tc;

    for(int i=1;i<=tc;i++)
    {
        cin>>num;
        for(int j=1;j<=num;j++)
            cin>>age[j];
        cout<<"Case "<<i<<": "<<age[(num+1)/2]<<endl;
    }
return 0;
}
