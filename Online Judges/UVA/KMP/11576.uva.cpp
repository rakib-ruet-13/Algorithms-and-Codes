#include<iostream>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int ind[10000000];

void pre_process(string patt)

{

    long long int i,j,m;
    m=patt.size();

    ind[0]=0;
    j=0;
    for(i=1;i<m;i++)
    {
        if(patt[i]==patt[j])
        {
            ind[i]=j+1;
            j++;
        }

        else
        {
            do
            {
                j=ind[j-1];
                if(patt[i]==patt[j])
                {
                    j=j+1;
                    ind[i]=j;
                    break;
                }
            }
            while(j>0);

            if(j==0)
            {
              ind[i]=j;
            }
        }
    }
}

long int Matching(string txt,string patt)
{
   long int n,m,i,j,cnt=0;
   n=txt.size();
   m=patt.size();
   j=0;
   for(i=0;i<n;i++)
   {
      if(txt[i]==patt[j])
      {
          j++;
      }
      else
      {

          do
          {
              j=ind[j-1];
              if(txt[i]==patt[j])
              {
                  j=j+1;
                  break;
              }
          }
          while(j>0);
      }
   }
     return j;

}

int main()
{
    int ans,tc,k,n,i,j;
    string str,txt[100];

    cin>>tc;
    while(tc--)
    {
        cin>>k>>n;
        getchar();
        for(i=0;i<n;i++)
        {
          cin>>txt[i];
        }
        str=txt[0];

        for(i=1;i<n;i++)
        {
            pre_process(txt[i]);
            ans=Matching(txt[i-1],txt[i]);

            for(j=ans;j<k;j++)
            {
                str.push_back(txt[i][j]);
            }
        }
        cout<<str.size()<<endl;
        txt[0].clear();
        str.clear();


    }
}

