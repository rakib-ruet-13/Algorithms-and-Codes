#include<iostream>
#include<bits/stdc++.h>
using  namespace std;



    struct node
    {
    int sum;
    int i;
    int j;
    }res;

node Subset_Sum(int arr[],int Sz)
{



    node curr_max,max_sum,res;
    curr_max.sum=max_sum.sum=-111111111;

    for(int i=0 ; i<Sz ; i++)
    {
        if(curr_max.sum<0)
        {
            curr_max.sum=arr[i];
            curr_max.i=i;
            curr_max.j=i;
        }
        else
        {
            curr_max.sum+=arr[i];
            curr_max.j=i;
        }



        if(max_sum.sum<curr_max.sum)
        {
            max_sum=curr_max;
        }

    }

    return max_sum;

}




int ract_arr_sum()
{
    int arr[100][100];

    int row,col;
    scanf("%d %d",&row,&col);


    for(int i=0; i<row ;i++)
        for(int j=0; j<col ; j++)
    {
        scanf("%d",&arr[i][j]);
    }

    int max_curr,max_sum,max_left,max_right,max_up,max_down;

    max_curr=max_sum=-1111111111;

    for(int l=0; l<col ; l++ )
    {
        int A[100];
        memset(A,0,sizeof(A));

        for(int r=l; r<col ; r++)
        {
           for(int i=0 ;i<row; i++)
           {
               A[i]+=arr[i][r];
           }
           res=Subset_Sum(A,row);

           if(res.sum>max_sum)
           {
               max_sum=res.sum;
               max_left=l;
               max_right=r;
               max_up=res.i;
               max_down=res.j;
           }

        }
    }
    printf("%d %d %d %d %d",max_sum,max_left,max_up,max_right,max_down);
}

int main()
{
    ract_arr_sum();
    return 0;
}
