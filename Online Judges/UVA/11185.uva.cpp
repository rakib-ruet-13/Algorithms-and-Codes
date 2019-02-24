#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    long long int num,sum,i;
    vector<int>vct;
    while(cin>>num && num>=0)
    {
        if(num==0)
            cout<<"0"<<endl;
        else
        {while(num)
        {
            vct.push_back(num%3);
            num=num/3;
        }
        reverse(vct.begin(),vct.end());
        sum=vct.size();
        for(i=0;i<sum;i++)
            cout<<vct[i];
        cout<<endl;
        vct.clear();
        }
    }
    return 0;
}
