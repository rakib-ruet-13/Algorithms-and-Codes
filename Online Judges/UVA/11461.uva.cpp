#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    long int a,b,ans;
    while(cin>>a>>b &&(a||b))
    {
        if(a>b)
            swap(a,b);
        a=ceil(sqrt((float)a));
        b=floor(sqrt((float)b));

        ans=b-a+1;
        cout<<ans<<endl;
    }
    return 0;

}

