/********************************************************/
/********************************************************/
/*************          RAKIB         *******************/
/************       CSE 13, RUET       ******************/
/***********          contact:           ****************/
/******     mail: rakib_cse13@outlook.com     ***********/
/*****           mobile : 01846207019           *********/
/********************************************************/
/********************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/******macros****/

#define Max 1000000
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid (x>=1 && x<=row && y>=1 && y<=col)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define pii pair<ll,ll>

/***** useful function ****/

ll power(ll base, ll p){ ll ans=1;if(p==0)return 1;for(ll i=1;i<=p;i++)ans*=base;return ans;}
ll gcd(ll a, ll b){if(a==0)return b;gcd(b,a%b);}


/***** Nececessary global variables ****/
ll row,col;
 vector<int> binary(ll n)
 {
    vector<int>vct;


    while(n!=0)
    {
        vct.pb(n%2);
        n=n/2;
    }
    return vct;

 }

 ll decimal(vector<int>vct)
 {
     ll p=vct.size()-1;

     ll sum;
     sum=0;

     for(int i=0;i<vct.size();i++)
     {
         sum+=(vct[i]*power(2,p));
         p--;
     }

     return sum;
 }



int main()
{

     vector<int>vct1,vct2;

     ll a,b;
     cin>>a>>b;

     if(a>b)
        swap(a,b);

        vct1=binary(a);
        vct2=binary(b);

          for(int i=vct1.size();i<vct2.size();i++)
            vct1.pb(0);



        reverse(vct1.begin(),vct1.end());
          reverse(vct2.begin(),vct2.end());



        bool flag=false;





        int cnt=0;

        for(int i=0;i<=vct1.size();i++)
        {
            if(vct1[i]==1)
             flag=true;

            if(flag==true && vct1[i]==0)
            {
                 cnt++;
                 if(cnt>1)
                    vct1[i]=1;
            }


        }




        ll comp2=decimal(vct2);
        ll comp1=decimal(vct1);

       // cout<<comp1<<comp2<<endl;


        vector<int>v;


        for(int i=0;i<vct1.size();i++)
        {
            v.pb(1);
        }

        //for(int i=0;i<v.size();i++)
            //cout<<v[i];

       // cout<<endl;

        int ans=0;



        for(int k=0;k<=v.size();k++)
        {
              flag=false;

        for(int i=k;i<v.size();i++)
        {

            if(v[i]==1 && flag==false)
                {
                    flag=true;

                    {
                          if(v.size()>1 && i<v.size()-1)
                          v[i+1]=0;
                    }

                    continue;
                }

            if(v[i]==0)
            {
                ll sum=decimal(v);

                //cout<<sum<<endl;

                if(sum>=comp1 && sum<=comp2)
                   {
                       ans++;
                   }

                v[i]=1;
                if(i!=vct1.size()-1)
                v[i+1]=0;


            }

        }
         for(int i=k;i<v.size();i++)
         {
             v[i]=1;

         }



            v[k]=0;


        }

        cout<<ans<<endl;








     return 0;


}






