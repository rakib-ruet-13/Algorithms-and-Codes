#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long a,b,mod,ans,temp;
    while(cin>>a>>b)
    {
        cout<<"["<<a/b<<";";
        a=a%b;

        swap(a,b);
        while(b!=0)
        {
            cout<<a/b;
            a=a%b;
            swap(a,b);
            if(b!=0)
                cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;

}
