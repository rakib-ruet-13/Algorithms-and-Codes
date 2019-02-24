#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/****gobal rows and coloums***/
typedef long long int ll;
int row1,col1,row2,col2;
ll ans[10][10];
ll mod;

/****declaring global constant , is to be multiplied with function ***/

static long long int C1,C2,C3;


/**Multitication function having result in ans of A=row1*col1 , B=row2*col2*/
void matrix_multi(ll A[10][10],ll B[10][10])
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
      for (int i=0; i<row1; i++)
        for (int j=0; j<col1; j++)
            A[i][j] = ans[i][j]%mod;  /*****we find the result in first parameter matrix*****/


}




ll power_mat(ll F[10][10],int n)
{

    /*****intializing MF Function matrix M ***/

       ll M[9][9]={
            {1,0,1,0,1,0,1,0,0},
            {1,0,0,0,0,0,0,0,0},
            {1,0,1,0,1,0,0,1,0},
            {0,0,1,0,0,0,0,0,0},
            {1,0,1,0,1,0,0,0,1},
            {0,0,0,0,1,0,0,0,0},
            {0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,0,0,1},
            };
     ll MF[10][10];

      for (int i=0; i<row1; i++)
         for (int j=0; j<col1; j++)
            MF[i][j] = M[i][j];

     power_mat(F,n/2);
     matrix_multi(F,F);

     if(n&1)
     matrix_multi(F,MF);

     return  F[0][1]+F[0][3]+F[0][5]+F[0][6]*12+F[0][7]*21+F[0][8]*30%mod;
}


ll get_nth_term(ll F[10][10],int n,int fn2,int fn1,int fn)
{
    mod=1000000007;
   // cout<<mod<<endl;

   C1=fn;     /*** f(n) f(n-1) f(n-2) initializing **/
   C2=fn1;
   C3=fn2;

    if(n==0)
         return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 63;

      return power_mat(F,n-2);

}

int main()
{
    int tc;
    scanf("%d",&tc);

    row1=col1=row2=col2=9;
    ll a,b,n,c;

    for(int cs=1; cs<=tc ; cs++)
    {
        scanf("%lld",&n);

        ll M[9][9]={
            {1,0,1,0,1,0,1,0,0},
            {1,0,0,0,0,0,0,0,0},
            {1,0,1,0,1,0,0,1,0},
            {0,0,1,0,0,0,0,0,0},
            {1,0,1,0,1,0,0,0,1},
            {0,0,0,0,1,0,0,0,0},
            {0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,0,0,1},
            };

        ll F[10][10];
        for (int i=0; i<row1; i++)
         for (int j=0; j<col1; j++)
            F[i][j] = M[i][j];

            a=b=c=1;


        printf("Case %d: %lld\n",cs,get_nth_term(F,n,a,b,c));
    }

}



