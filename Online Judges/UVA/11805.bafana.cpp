#include<iostream>
using namespace std;

int main()
{
    long long int tc,n,k,p,temp,i=1;

    cin>>tc;
    while(tc--)
    {


        cin>>n>>k>>p;
        cout<<"Case "<<i++<<": ";
        temp=p%n;
        if(k+temp>n)
            cout<<(k+temp)-n<<endl;
        else
            cout<<k+temp<<endl;


    }
    return 0;
}
