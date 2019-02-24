#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/****gobal rows and coloums***/
typedef  long long int ll;
int row1,col1,row2,col2;
ll ans[10][10];
ll mod;
static ll a1,b1,c1,a2,b2,c2;
ll f0,f1,f2,g0,g1,g2;

/****declaring global constant , is to be multiplied with function ***/




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
       ll M[6][6]={{a1,b1,0,0,0,c1},
                    {1,0,0,0,0,0},
                    {0,1,0,0,0,0},
                    {0,0,c2,a2,b2,0},
                    {0,0,0,1,0,0},
                    {0,0,0,0,1,0}};
        ll MF[10][10];

      for (int i=0; i<row1; i++)
         for (int j=0; j<col1; j++)
            MF[i][j] = M[i][j];

    if(n==1)
       {
          return  0;
       }

     power_mat(F,n/2);
     matrix_multi(F,F);


     if(n&1)
     matrix_multi(F,MF);

     return  0;
}


ll get_nth_term(ll F[10][10],ll n)
{
    if(n==0)
        {
            printf("%lld %lld\n",f0%mod,g0%mod);
            return 0;
        }

    if(n==1)
       {
          printf("%lld %lld\n",f1%mod,g1%mod);
          return 0;
       }
    if(n==2)
        {
            printf("%lld %lld\n",f2%mod,g2%mod);
            return 0;
        }


    power_mat(F,n-2);

     ll res1= ( F[0][0]*f2 + F[0][1]*f1 + F[0][2]*f0 + F[0][3]*g2 + F[0][4]*g1 + F[0][5]*g0 )%mod;
     ll res2= ( F[3][0]*f2 + F[3][1]*f1 + F[3][2]*f0 + F[3][3]*g2 + F[3][4]*g1 + F[3][5]*g0 )%mod;

     printf("%lld %lld\n",res1,res2);


      return 0;

}

int main()
{
    int tc;
    scanf("%d",&tc);

    row1=col1=row2=col2=6;
    ll p,q,n;

    for(int cs=1; cs<=tc ; cs++)
    {
        scanf("%lld %lld %lld",&a1,&b1,&c1);
         scanf("%lld %lld %lld",&a2,&b2,&c2);

          scanf("%lld %lld %lld",&f0,&f1,&f2);
           scanf("%lld %lld %lld",&g0,&g1,&g2);

        scanf("%lld",&mod);

        ll M[6][6]={{a1,b1,0,0,0,c1},
                    {1,0,0,0,0,0},
                    {0,1,0,0,0,0},
                    {0,0,c2,a2,b2,0},
                    {0,0,0,1,0,0},
                    {0,0,0,0,1,0}};

         ll F[10][10];
         for (int i=0; i<row1; i++)
         for (int j=0; j<col1; j++)
            F[i][j] = M[i][j];



        int q;

        printf("Case %d:\n",cs);

        scanf("%d",&q);

        while(q--)
        {

         for (int i=0; i<row1; i++)
         for (int j=0; j<col1; j++)
            F[i][j] = M[i][j];

            scanf("%lld",&n);
             get_nth_term(F,n);
        }


    }

}





