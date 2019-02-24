#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[30];

int main()
{
      map<string,int>mymap;
      map<string,int> ::iterator it,it1;

    string str[101];

    long long int n;

    cin>>n;
    getchar();

    for(int i=0;i<n;i++)
    {
          getline(cin,str[i]);
          for(int k=0;k<str[i].size();k++)
          {
              arr[str[i][k]-(int)('a')]++;
          }

          int cnt=0;
          int sum=0;
          string st;

          for(int m=0;m<26;m++)
          {
              if(arr[m]>0)
                {
                    st+=char('a'+int(m));
                    sum+=arr[m];
                    cnt++;
                }

          }
          if(cnt<=2)
            mymap[st]+=sum;

            for(int m=0;m<26;m++)
                arr[m]=0;

    }





    for(it=mymap.begin();it!=mymap.end();it++)
    {
       if(it->first.size()==2)
       {
           string str1,str2;

            str1+=it->first[0];
            str2+=it->first[1];
           it->second+=mymap[str1]+mymap[str2];
       }
    }


    long int Max=0;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        if(it->second>Max)
        {
            Max=it->second;
        }
    }

     for(it=mymap.begin();it!=mymap.end();it++)
     {
         if(it->first.size()==1)
         {
             it1=it;
             it1++;
             for( ;it1!=mymap.end();it1++)
             {
                  if(it1->first.size()==1)
                  {
                      if(it->second+it1->second>Max)
                        Max=it->second+it1->second;
                  }
             }
         }
     }



    cout<<Max<<endl;





}
