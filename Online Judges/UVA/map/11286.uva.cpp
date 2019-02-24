#include<iostream>
#include<cstring>
#include<map>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
    long int i,j,n,arr[5],mx,sum;
    map<string,int>com;
    map<string,int>::iterator it;
    vector<char>str;
    string st;

    while(cin>>n && n!=0)
    {
        for(i=0;i<n;i++)
        {

         for(j=0;j<5;j++)
            {
               cin>>arr[j];
            }

             sort(arr,arr+5);



             for(j=0;j<5;j++)
              {
                str.push_back(char((arr[j]/100)+48));
                arr[j]=arr[j]%100;
                str.push_back(char((arr[j]/10)+48));
                arr[j]=arr[j]%10;
                str.push_back(char((arr[j]/1)+48));
              }

            for(int k=0;k<15;k++)
             {
             st.push_back(str[k]);
             }


              //cout<<st<<endl;

           com[st]++;

           str.clear();
           st.clear();
        }


        mx=1;
        for(it=com.begin();it!=com.end();it++)
        {
          if(it->second>mx)
                mx=it->second;
               // cout<<it->second<<endl;;
        }
        sum=0;
         for(it=com.begin();it!=com.end();it++)
        {

               if( mx==it->second)
                 sum=sum+it->second;
        }

        if(mx==1)
            cout<<n<<endl;
        else
            cout<<sum<<endl;
        com.clear();

    }



}
