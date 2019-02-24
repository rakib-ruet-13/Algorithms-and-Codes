#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long int tc,n,inp,max,cs=1;

    cin>>tc;
    while(tc--)
    {
        cin>>n;
        max=-9999999;
        for(int i=1;i<=n;i++)
        {
            cin>>inp;
            if(inp>max)
            {
                max=inp;
            }
        }
        cout<<"Case "<<cs++<<": "<<max<<endl;
    }
    return 0;

}
