#include<iostream>
#include<cstring>
#include<ctype.h>
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
      if(j==m)
      {
          cnt++;
          j=ind[j-1];
      }
   }
   return cnt;

}

int main()
{
    int ans,tc,cs=0;
    string str,txt;
    cin>>tc;
    getchar();

    while(tc--)
    {
        getline(cin,txt);
        getline(cin,str);
        pre_process(str);
        ans=Matching(txt,str);

        cout<<"Case "<<++cs<<": "<<ans<<endl;
        txt.clear();
        str.clear();
    }

}
