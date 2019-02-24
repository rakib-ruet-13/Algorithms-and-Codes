#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int num,i,cs=1;
    while(cin>>num && num>0)
    {   if(num==1)
        cout<<"Case "<<cs++<<": "<<"0"<<endl;
        else
        {
        i=0;
        while(pow(2,i)<num)
            i++;
        cout<<"Case "<<cs++<<": "<<i<<endl;
        }
    }
    return 0;
}
