#include<iostream>
#include<bits/stdc++.h>
#define M1 1000000007
#define M2 1000000003
#define poly 101

using namespace std;

typedef long long ll;

ll mod_poly[100010][3];

inline ll Bmod(ll b, ll p,ll m,int flag)
{
    if(mod_poly[p][flag]!=-1)
        return mod_poly[p][flag];

    if(p==0)
        return 1;

    if(p%2==0)
    {
        ll res=Bmod(b,p/2,m,flag);
        return mod_poly[p][flag]=(res*res)%m;
    }

    return mod_poly[p][flag]=((b%m)*(Bmod(b,p-1,m,flag)))%m;
}






void Gen_mod_poly()
{
    for(int i=0; i<=100000; i++)
    {
        mod_poly[i][0]=-1;
        mod_poly[i][1]=-1;
    }


    for(int i=0; i<=100000; i++)
        mod_poly[i][0]=Bmod(poly,i,M1,0);

      for(int i=0; i<=100000; i++)
        mod_poly[i][1]=Bmod(poly,i,M2,1);
}


/**** x is polynomial base */
ll Hash_value(string str,ll x,ll mod,int flag)
{
    ll h=0;
    for(int i=0; i<str.size() ; i++)
    {
        h+= ((ll)(str[i])*Bmod(x,i,mod,flag))%mod;
        h%=mod;
    }
    return h;
}

/*****str is string T is substring**/
ll Hash(string str,string T,ll x,ll mod,int flag)
{
    if(str.size()<T.size())
        return 0;

    ll T_hash=Hash_value(T,x,mod,flag);
    ll T_len=T.size();
    ll N=str.size();
    /*** st is current substring ***/
    string st;
    st.clear();

    for(int i=N-T_len; i<N; i++)
        st+=str[i];

    ll curr=Hash_value(st,x,mod,flag);

    if(curr==T_hash)
      return 1;

    ll prev;
    for(ll i=N-T_len; i>0 ; i--)
    {
        prev=(curr*x)%mod+(str[i-1])-(str[i+T_len-1]*(Bmod(x,T_len,mod,flag)))%mod;
        prev=(prev+mod)%mod;

        if(prev==T_hash)
        {
            return 1;
        }
        curr=prev;
    }

    return 0;
}


int main()
{

    Gen_mod_poly();

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        string str1,str2;
        int q;
        cin>>str1>>q;

        while(q--)
        {
            cin>>str2;
            if(Hash(str1,str2,poly,M1,0) && Hash(str1,str2,poly,M2,1))
                cout<<"found\n";
            else
                cout<<"not found\n";
        }
    }
    return 0;
}
