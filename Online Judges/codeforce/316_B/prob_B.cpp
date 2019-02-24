#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long int n,m;

    while(cin>>n>>m)
    {

        if(n==1)
            cout<<1<<endl;
        else if(n/2>=m)
        cout<<m+1<<endl;
        else
            cout<<m-1<<endl;

    }
    return 0;

}
