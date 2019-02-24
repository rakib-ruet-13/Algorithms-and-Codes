#include<iostream>
#include<string>
#include<algorithm>
#include<ctype.h>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main()
{

    char vct[400000],tmp[400000];
    char ch,test;
    long long int n,m,ind,i,ll,ul,flag,cnt,sum;

    while(cin>>n>>m)
    {
        getchar();
        for(i=0;i<n;i++)
            {
                ch=getchar();
                vct[i]=ch;
            }
        cnt=m;
        while(m--)
        {
            cin>>ind>>ch;
            test=vct[ind-1];
            vct[ind-1]=ch;

           // cout<<endl;
           if(m==cnt-1)
           {

             flag=0;
             sum=0;
             ll=0;
             ul=0;
           //cout<<cnt<<endl;
            for(long int K=0 ; K<n ;K++)
            {
                if((vct[K]=='.') && flag==0)
                    {

                       // cout<<i<<endl;
                        ll=K;
                        ul=ll;
                        //cout<<ul<<endl;
                        flag=1;
                    }
                if(vct[K]!='.' && flag==1)
                {

                    ul=K-1;
                    //cout<<ul<<endl;
                    flag=0;
                     sum = sum + ul-ll;
                }
                else if(K==n-1 && flag==1)
                {
                    ul=n-1;
                     sum = sum + ul-ll;
                }

                //cout<<cnt<<endl;
            }



           }
           else if((test!='.' && ch!='.') || (test=='.' && ch=='.'))
           {
               sum=sum+0;
           }
           else
           {
              if(ch=='.')
              {
                  if(ind!=1)
                   if(vct[ind-2]=='.')
                     sum=sum+1;

                  if(ind!=n)
                  if(vct[ind]=='.')
                    sum=sum+1;
              }
              if(ch!='.')
              {

                  if(ind!=1)
                  if(vct[ind-2]=='.')
                  sum=sum-1;

                  if(ind!=n)
                  if(vct[ind]=='.')
                    sum=sum-1;
              }

           }
            cout<<sum<<endl;

        }
    }

}
