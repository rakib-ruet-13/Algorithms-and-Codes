#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x);
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)
#define mem(x,val) memset(x,val,sizeof(x))
#define Max 50001


int main()
{
    ll n;

    string str1,str;
    cin>>n;

    cin>>str1;


    for(int i=0;i<str1.size();i++)
        str+=str1[i];

    for(int i=0;i<str1.size();i++)
        str+=str1[i];


    for(int i=0;i<str1.size();i++)
        str+=str1[i];


    //cout<<str<<endl;

    map<char,int>mymap;

    for(int i=0; i<str.size() ; i++)
    {
        mymap[str[i]]++;
    }

    int mx;
    mx=mymap.size();

    mymap.clear();


    int i=0;
    int j=0;

    int cnt=0;
    int mn=9999999;

    while(i<str.size())
    {
       if(cnt<mx)
       {
           if(j>=str.size())
            break;

           if(mymap[str[j]]==0)

            {
                cnt++;

            }
            mymap[str[j]]++;

            j++;
       }
       else
       {
           mn=min(mn,j-i);
           mymap[str[i]]--;

           if(mymap[str[i]]==0)
           {
              cnt--;
           }
           i++;
       }



    }

    cout<<mn<<endl;









    return 0;
}

