#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/****gobal rows and coloums***/
typedef long long int ll;
int row1,col1,row2,col2;
ll ans[2][2];
ll mod;

/**Multitication function having result in ans of A=row1*col1 , B=row2*col2*/
void matrix_multi(ll A[2][2],ll B[2][2])
{
    memset(ans,0,sizeof(ans));
    for(int i=0; i<row1 ; i++)
    {
        for(int j=0 ; j<col2 ; j++)
        {
            ans[i][j]=0;
            for(int k=0; k<row2; k++)
            {
                ans[i][j]+=(A[i][k]*B[k][j])%mod;
            }
        }
    }
      for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            A[i][j] = ans[i][j]%mod;
}

ll power_mat(ll F[2][2],int n,ll a,ll b)
{
      ll M[2][2]={{1,1},{1,0}};

    if(n==1)
        return  (F[0][0]*b +  F[0][1]*a )%mod ;

     power_mat(F,n/2,a,b);
     matrix_multi(F,F);

     if(n&1)
     matrix_multi(F,M);

     return  (F[0][0]*b+ F[0][1]*a)%mod   ;
}


ll get_nth_term(ll F[2][2],int n,ll a,ll b,ll m)
{
    mod=1;

    for(int i=1; i<=m ;i++)
    {
       mod*=10;
    }

   // cout<<mod<<endl;

    if(n==0)
        return a;
    if(n==1)
        return b;

      return power_mat(F,n-1,a,b);

}

int main()
{
    int tc;
    scanf("%d",&tc);

    row1=col1=row2=col2=2;
    ll a,b,n,m;

    for(int cs=1; cs<=tc ; cs++)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&n,&m);

        ll M[2][2]={{1,1},{1,0}};
        printf("Case %d: %lld\n",cs,get_nth_term(M,n,a,b,m));
    }

}

