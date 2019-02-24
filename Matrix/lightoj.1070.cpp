#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/****gobal rows and coloums***/
typedef unsigned long long int ll;
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
                ans[i][j]+=(A[i][k]*B[k][j]);
            }
        }
    }
      for (int i=0; i<row1; i++)
        for (int j=0; j<col1; j++)
            A[i][j] = ans[i][j];  /*****we find the result in first parameter matrix*****/


}




ll power_mat(ll F[10][10],int n)
{

    /*****intializing MF Function matrix M ***/
      ll M[2][2]={{C1,-C3},{1,0}};
      ll MF[10][10];

      for (int i=0; i<row1; i++)
         for (int j=0; j<col1; j++)
            MF[i][j] = M[i][j];

    if(n==1)
       {
          return  F[0][0]*C1+F[0][1]*2;
       }

     power_mat(F,n/2);
     matrix_multi(F,F);


     if(n&1)
     matrix_multi(F,MF);

     return  F[0][0]*C1+F[0][1]*2;
}


ll get_nth_term(ll F[10][10],ll n,ll p,ll q)
{
   // mod=10007;
   // cout<<mod<<endl;

   C1=p;     /*** f(n) f(n-1) f(n-2) initializing **/
   C2=2;
   C3=q;

    if(n==0)
        return 2;
    if(n==1)
        return p;


      return power_mat(F,n-1);

}

int main()
{
    int tc;
    scanf("%d",&tc);

    row1=col1=row2=col2=2;
    ll p,q,n;

    for(int cs=1; cs<=tc ; cs++)
    {
        scanf("%llu %llu %llu",&p,&q,&n);

        ll M[2][2]={{p,-q},{1,0}};
        ll F[10][10];
        for (int i=0; i<row1; i++)
         for (int j=0; j<col1; j++)
            F[i][j] = M[i][j];


        printf("Case %d: %llu\n",cs,get_nth_term(F,n,p,q));
    }

}




