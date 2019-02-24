#include<iostream>
#include<cstring>
#include<ctype.h>
#include<bits/stdc++.h>
using namespace std;

int ind[1000001];

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

long long int Matching(string txt,string patt)
{
   long long int n,m,i,j,cnt=0,mx=0;
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
   mx=j;
   return mx;

}



int main()
{
    long long int ans,mx,i,n;
    string str,txt;


    while( getline(cin,txt))
    {

        str=txt;
        n=txt.size();
        reverse(str.begin(),str.end());

        pre_process(str);
        mx=Matching(txt,str);

        for(i=0;i<n;i++)
        {
            cout<<txt[i];
        }
        for(i=n-mx-1;i>=0;i--)
            cout<<txt[i];
        cout<<endl;

        txt.clear();
        str.clear();
    }

}


