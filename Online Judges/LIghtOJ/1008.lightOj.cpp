#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long int tc,num,root,midd,i;
    cin>>tc;
    for(i=1;i<=tc;i++)
    {
        cin>>num;
        root=ceil(sqrt((double)num));
        midd=root*root-root+1;

        if(midd<num)
        {
            if(root%2==0)
                cout<<"Case "<<i<<": "<<root<<" "<<root-abs(midd-num)<<endl;
            else
                cout<<"Case "<<i<<": "<<root-abs(midd-num)<<" "<<root<<endl;
        }
        else
        {
            if(root%2==0)
                 cout<<"Case "<<i<<": "<<root-abs(midd-num)<<" "<<root<<endl;
            else
                cout<<"Case "<<i<<": "<<root<<" "<<root-abs(midd-num)<<endl;
        }
    }
    return 0;

}
