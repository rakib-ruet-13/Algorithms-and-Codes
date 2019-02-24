#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long int tc,num,root,midd,i;
    while(cin>>num && num)
    {
        root=ceil(sqrt((double)num));
        midd=root*root-root+1;

        if(midd<num)
        {
            if(root%2==0)
                cout<<root<<" "<<root-abs(midd-num)<<endl;
            else
                cout<<root-abs(midd-num)<<" "<<root<<endl;
        }
        else
        {
            if(root%2==0)
                 cout<<root-abs(midd-num)<<" "<<root<<endl;
            else
                cout<<root<<" "<<root-abs(midd-num)<<endl;
        }
    }
    return 0;

}

