#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
    int tc,n,q,p,cnt,num,cs=0,sum,i;
    vector<int>vct;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>p>>q;
        for(i=0;i<n;i++)
        {
            cin>>num;
            vct.push_back(num);
        }

        sort(vct.begin(),vct.end());
        sum=0;
        i=0;
        cnt=0;
        while(i<p && i<n)
        {
            if(sum+vct[i]>q )
                break;
            sum=sum+vct[i];
            cnt++;
            i++;
        }
        cout<<"Case "<<++cs<<": "<<cnt<<endl;
        vct.clear();

    }
    return 0;


}
