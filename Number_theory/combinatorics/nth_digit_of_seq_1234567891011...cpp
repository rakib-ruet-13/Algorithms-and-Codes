#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int power(int n,int p)
{
    if(p==0)
        return 1;


    int res=1;

    for(int i=1 ; i<=p ;i++)
    {
        res*=n;
    }

    return res;
}



int main()
{

    int n;
    int ds,d,nth,sum,mod,res;


    int dig;



    while(cin>>n)
    {
     sum=n;
     bool flag=0;

    for(int i=1; sum >0 ; i++)
    {
         d=power(10,i)-power(10,i-1);
         ds=i*d;

        if(sum>ds)
        {
            sum=sum-ds;
        }
        else
        {
             nth=sum/i;
             mod=sum%i;
             dig=i;

             if(mod>0)
               {
                   nth++;
                   flag=1;
               }

             res=power(10,i-1)+nth-1;

             break;
        }

    }


    if(mod==0)
        cout<<res%10<<endl;
    else
       cout<<(res/power(10,dig-mod))%10<<endl;

    }

}

