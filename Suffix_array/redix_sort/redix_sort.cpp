#include<bits/stdc++.h>
#define Max 1010
using namespace std;

struct cord
{
    int u;
    int v;
    int pos;
};
cord arr[Max];
vector<cord>vct1[Max], vct2[Max];
vector<cord> redix_sort(int len)
{

    vector<cord>res;

    res.clear();
    for(int i=0; i<=len+10; i++) { vct1[i].clear();vct2[i].clear();}

    /** arr can have -1 value**/
    for(int i=0; i<len; i++) { int p=1+arr[i].v; vct1[p].push_back(arr[i]);}

    for(int i=0; i<=len+5; i++)
    {
        if(vct1[i].size()>0)
            for(int j=0; j<vct1[i].size(); j++)
            {
                int p=1+vct1[i][j].u;
                vct2[p].push_back(vct1[i][j]);
            }
    }

    for(int i=0; i<=len+5; i++)
    {
        if(vct2[i].size()>0)
            for(int j=0; j<vct2[i].size(); j++)
                res.push_back(vct2[i][j]);
    }
    return res;

}


int main()
{
    freopen("inp.txt","r",stdin);

    int n;
    cin>>n;
    for(int i=0; i<n;i++)
    {
        int p,q; cin>>p>>q;
        arr[i].u=p;
        arr[i].v=q;
        arr[i].pos=i;
    }

    vector<cord>res;
    res.clear();
    res=redix_sort(n);

    for(int i=0; i<res.size(); i++)
    {
        cout<<" "<<res[i].u<<"  "<<res[i].v<<"  "<<"  "<<res[i].pos<<endl;

    }



    return 0;
}
