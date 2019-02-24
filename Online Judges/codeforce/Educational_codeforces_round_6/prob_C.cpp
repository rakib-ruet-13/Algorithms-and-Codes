#include<iostream>
#include<bits/stdc++.h>

using namespace std;

map<long long,long long>mymap;
#define Max 300004

vector<int>vct;

long long int arr[Max+1];

int main()
{
    int n;
    cin>>n;


    int st=1;
    int cnt=0;

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        mymap[arr[i]]++;

        if(mymap[arr[i]]==2)
        {
            mymap.clear();

            vct.push_back(st);
            vct.push_back(i);
            st=i+1;
            cnt++;

        }
    }


    if(vct.size()==0)
    {
        cout<<-1<<endl;
        return 0;
    }

     cout<<cnt<<endl;


    for(int i=0;i<vct.size();i+=2)
    {
       if(i!=vct.size()-2)
       cout<<vct[i]<<" "<<vct[i+1]<<endl;
       else
        cout<<vct[i]<<" "<<n<<endl;

    }



}
