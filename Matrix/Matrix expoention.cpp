#include<iostream>
#include<bits/stdc++.h>
#define a 1
#define b 1
#define c 0
using namespace std;


/****gobal rows and coloums***/
typedef long long int ll;
int row1,col1,row2,col2;
ll ans[3][3];


/**Multitication function having result in ans of A=row1*col1 , B=row2*col2*/
void matrix_multi(ll A[3][3],ll B[3][3])
{
    memset(ans,0,sizeof(ans));
    for(int i=0; i<=row1 ; i++)
    {
        for(int j=0 ; j<col2 ; j++)
        {
            ans[i][j]=0;
            for(int k=0; k<row2; k++)
            {
                ans[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
      for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            A[i][j] = ans[i][j];
}

ll power_mat(ll F[3][3],int n)
{
    ll M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
    if(n==1)
        return  F[0][0]*a +  F[0][1]*b  +   F[0][2]*c;
     power_mat(F,n/2);
     matrix_multi(F,F);
     if(n&1)
     matrix_multi(F,M);
     return  F[0][0]*a +  F[0][1]*b  +   F[0][2]*c;
}


ll get_nth_term(ll F[3][3],int n)
{
      return power_mat(F,n-2);

}

int main()
{

    row1=col1=row2=col2=3;

    while(1)
    {
        int n;
        cin>>n;
         ll M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
        cout<<get_nth_term(M,n);
    }

    return  0;
}
