#include<iostream>
using namespace std;
int main()
{

    int num1,num2,ans,div,sum,tc;

    cin>>tc;


    while(tc--)
    {

        cin>>num1>>num2>>div;
        ans=0;
        sum=num1+num2;

        while(sum>=div)
        {
            ans+=sum/div;
            sum=sum/div+sum%div;

        }
        cout<<ans<<endl;

    }

    return 0;

}

