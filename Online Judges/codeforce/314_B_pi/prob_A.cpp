#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


int main()
{

    vector<long long int>vct,Min,Max;
    long long int n,num,i,l,m;

    while(cin>>n)
    {

    for( i=0;i<n;i++)
    {
        cin>>num;
        vct.push_back(num);
    }
    l=vct.size();

    Min.push_back(vct[1]-vct[0]);
    Max.push_back(vct[l-1]-vct[0]);

    for(i=1;i<l-1;i++)
    {
        m= min((vct[i]-vct[i-1]),(vct[i+1]-vct[i]));
        Min.push_back(m);
        Max.push_back(max((vct[l-1]-vct[i]),(vct[i]-vct[0])));
    }

    Min.push_back(vct[l-1]-vct[l-2]);
    Max.push_back(vct[l-1]-vct[0]);

    for(i=0;i<n;i++)
    {
        cout<<Min[i]<<" "<<Max[i]<<endl;
    }

    vct.clear();
    Min.clear();
    Max.clear();

    }


    return 0;
}
