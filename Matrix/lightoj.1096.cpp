#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/****gobal rows and coloums***/
typedef long long int ll;
int row1,col1,row2,col2;
ll ans[4][4];
ll mod;

/**Multitication function having result in ans of A=row1*col1 , B=row2*col2*/
void matrix_multi(ll A[4][4],ll B[4][4])
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
      for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            A[i][j] = ans[i][j]%mod;
}

ll power_mat(ll F[4][4],int n,ll a,ll b,ll c)
{
     ll M[4][4]={{a,0,b,1},{1,0,0,0},{0,1 ,0,0},{0,0 ,0,1}};


    if(n==1)
        return  (F[0][3]*c)%mod;

     power_mat(F,n/2,a,b,c);
     matrix_multi(F,F);

     if(n&1)
     matrix_multi(F,M);

     return  (F[0][3]*c)%mod;  ;
}


ll get_nth_term(ll F[4][4],int n,ll a,ll b,ll c)
{
    mod=10007;


    if(n==0 || n==1 || n==2)
        return 0;

      return power_mat(F,n-2,a,b,c);

}

int main()
{
    int tc;
    scanf("%d",&tc);

    row1=col1=row2=col2=4;
    ll a,b,n,c;

    for(int cs=1; cs<=tc ; cs++)
    {
        scanf("%lld %lld %lld %lld",&n,&a,&b,&c);

        ll M[4][4]={{a,0,b,1},{1,0,0,0},{0,1 ,0,0},{0,0 ,0,1}};
        printf("Case %d: %lld\n",cs,get_nth_term(M,n,a,b,c));
    }

}


