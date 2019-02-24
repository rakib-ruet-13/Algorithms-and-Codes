#include<iostream>
using namespace std;

int main()
{
     long long int i,dp[16];
     long long int ans=1,num;

    for(i=2;i<14;i++)
    {
        ans=ans*i;
        dp[i]=ans;
        //cout<<dp[i]<<endl;
    }
    while(cin>>num)
    {
        if(num<0 && num%2!=0)
            cout<<"Overflow!"<<endl;
        else if(num<0 && num%2==0)
            cout<<"Underflow!"<<endl;
          else if(num<8)
            cout<<"Underflow!"<<endl;
             else if(num>13)
               cout<<"Overflow!"<<endl;
            else
            cout<<dp[num]<<endl;
    }


}
