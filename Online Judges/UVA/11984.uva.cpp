#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{

    long long int tc,cs=1,c,f;
    double sum,temp;
    cin>>tc;
    while(tc--)
    {
        cin>>c>>f;
        temp=((double)c*(double)9/(double)5)+32+f;
        sum=((double)(temp-32)*(double)5/(double)9);
        cout<<fixed<<setprecision(2);
        cout<<"Case "<<cs++<<": "<<sum<<endl;

    }
    return 0;

}
