#include<iostream>
#include<map>
#include<iterator>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{

    int i,j,k;
    string str;
    map<string,int>MyMap;
    map<string,int>::iterator It;
    cin>>i;

    while(i--)
    {
        getchar();
       cin>>str;
       cin>>k;
       MyMap[str]=k;

    }

    for(It=MyMap.begin();It!=MyMap.end();It++)
    {
        cout<<It->first<<"  "<<It->second<<endl;
    }

}
