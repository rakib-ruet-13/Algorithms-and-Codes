#include<bits/stdc++.h>
using namespace std;

map<string, vector<string> >mymap,ans;

bool comp(string a,string b)
{
    return a.size()>b.size();
}
 int arr[100010];
int main()
{

    string name,temp;
    int N,n;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>name;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
           cin>>temp;
           mymap[name].push_back(temp);
        }
    }

    vector<string>vct;

    for( auto it=mymap.begin() ; it!=mymap.end() ; it++)
    {
        name=it->first;
        vct=it->second;

        sort(vct.begin(),vct.end(),comp);

        memset(arr,0,sizeof(arr));

        for(int i=0; i<vct.size() ; i++)
        {


            if(arr[i]!=0)
                continue;

            if(arr[i]==0)
                ans[name].push_back(vct[i]);

            for(int j=i+1; j<vct.size() ; j++)
            {
                string str1=vct[i];
                string str2=vct[j];

                reverse(str1.begin(),str1.end());
                reverse(str2.begin(),str2.end());

                int flag=1;

                for(int p=0; p<str2.size(); p++)
                {
                    if(str1[p]!=str2[p])
                    {
                        flag=0;
                        break;
                    }
                }

                if(flag)
                    arr[j]=1;

            }


        }
        vct.clear();


    }

    cout<<mymap.size()<<endl;
    for(auto it=ans.begin() ; it!=ans.end() ; it++)
    {
        cout<<it->first;
        vector<string>vct;
        vct=it->second;
        cout<<" "<<vct.size();

        for(int i=0; i<vct.size() ;i++)
            cout<<" "<<vct[i];

        cout<<endl;
        vct.clear();


    }

    return 0;
}
