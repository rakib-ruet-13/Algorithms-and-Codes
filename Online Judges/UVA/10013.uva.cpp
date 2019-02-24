#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{

    vector<int>num1;
    vector<int>num2;
    vector<int>ans;

    long int tc,n,i,j,num,sum,hand,l;
    cin>>tc;
    while(tc--)
    {
        cin>>n;

        for(i=0;i<n;i++)
        {
            cin>>num;
            num1.push_back(num);
            cin>>num;
            num2.push_back(num);
        }
        hand=0;
        for(i=n-1;i>=0;i--)
        {
           sum=(num1[i]+num2[i]+hand);
           hand=sum/10;
           ans.push_back(sum%10);
        }

        if(hand==1)
            ans.push_back(1);

        l=ans.size();
        for(i=l-1;i>=0;i--)
        {
            cout<<ans[i];
        }
        cout<<endl;

        if(tc!=0)
        cout<<endl;

        num1.clear();
        num2.clear();
        ans.clear();


    }

    return 0;


}
