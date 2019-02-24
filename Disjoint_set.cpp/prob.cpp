#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int cnt;

int part(int arr[], int st,int ed)
{
    int mid=(st+ed)/2;

    swap(arr[mid],arr[ed]);
    int pivot=arr[ed];
    int index=st;

    for(int i=st;i<=ed-1;i++)
    {
        cnt++;

        if(arr[i]<pivot)
        {
            swap(arr[i],arr[index]);
            index++;
        }
        else
        {
            if(arr[i]==pivot)
            {
                if(index<mid)
                {
                    swap(arr[i],arr[index]);
                    index++;
                }
            }
        }


    }
    swap(arr[index],arr[ed]);

    return index;



}


int max_find(int arr[],int st,int ed,int nth)
{
   // int s=sizeof(arr);
   // if(s<nth-1 || nth-1<0)
       // return -1;

    if(st<=ed)
    {
        cnt++;
        int p_index=part(arr,st,ed);
          if(p_index==nth-1)
          {
              return arr[p_index];
          }
          else if(p_index>nth-1)
          {
              return max_find(arr,st,p_index-1,nth);
          }
          else
          {
               return max_find(arr,p_index+1,ed,nth);
          }
    }

}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main()
{
    int arr[100000];

    for(int i=0;i<1000;i++)
    {
        arr[i]=i+2;
    }

    //print(arr,10);


        cnt=0;
        //cout<<i<<"th data = ";
        max_find(arr,0,999,50);

        cout<<"       Total count = "<<cnt<<endl;



}

