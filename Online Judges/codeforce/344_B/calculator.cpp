#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void calcu(ll a,ll b,string str)
{
    if(str=="+")
    {
        printf("The result of %lld + %lld is: %lld\n",a,b,a+b);
    }
    else if(str=="-")
    {
        printf("The result of %lld - %lld is: %lld\n",a,b,a-b);
    }
     else if(str=="*")
    {
         printf("The result of %lld * %lld is: %lld\n",a,b,a*b);
    }
     else if(str=="/")
    {
         printf("The result of %lld / %lld is: %lf\n",a,b,(double)a/(double)b);
    }
}



int main()
{
    string str;

    printf("Put your name : ");
    getline(cin,str);

    int cnt=1;
    bool flag=1;
    do
    {
        if(cnt==0)
         cout<<str<<" , do u want to use the calculator: ";
        else
        cout<<str<<" , do u want to use the calculator again: ";

         cout<<"\nput 1 to use or any other to terminate\n";

         string choice;

         cin>>choice;



         if(choice=="1")
         {
             cout<<"\nPut two operands:\n";
             long long int a,b;

             cin>>a>>b;

             cout<<"Put the operator:"<<endl;
             string op;
             cin>>op;

             calcu(a,b,op);

         }
         else
            {
                break;
                flag=0;
            }

            cnt++;



    }while(cnt<=4);

    if(flag==1)
    {
        printf("\nYou have used the highest 4 times , thats all\n");
    }
    printf("\nThanks for using . see u again \n");

    getchar();

    return 0;


}
