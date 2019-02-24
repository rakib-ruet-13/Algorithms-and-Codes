#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{

    int n,b,d;


   cin>>n>>b>>d;

    int cnt=0;
    int sum=0;
    for(int i=1; i<=n ;i++)
    {
        int temp;
        cin>>temp;

        if(temp>b)
        {
            sum+=temp;
        }

        if(sum>d)
        {
            sum=0;
            cnt++;
        }

    }


    cout<<cnt<<endl;




    return 0;
}
