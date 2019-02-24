#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll num;



ll rev(ll n)
{
    int res=0;

    while(n)
    {
        res=res*10+(n%10);
        n=n/10;
    }

    return res;
}

ll palindrome(ll n)
{

    int cnt=0;

    do
    {
     ll m=rev(n);
     if(n==m)
     {
        num=m;
        printf("Your desired palindrome no id : %lld\n",m);
        return cnt;
     }
     n=n+m;
     cnt++;
    }
    while(cnt<=20);

    return cnt;
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
         cout<<str<<" , do u want to make a palindrome: ";
        else
        cout<<str<<" , do u want to make a palindrome again: ";

         cout<<"\nput 1 to make or any other to terminate\n";

         string choice;

         cin>>choice;



         if(choice=="1")
         {
             cout<<"\nPut a number \n";
             long long int n;

             cin>>n;
             int cnt;
             cnt=palindrome(n);
             if(cnt==0)
                printf("Your number is already a palindrome hence no step requires \n");
             else if(cnt<=20)
                 printf("it took %d steps to make %d palindrome\n",cnt,n);
             else
                printf("it exceeded more then 20 steps hence could not make the palindrome\n ");


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

