#include<iostream>
#include<cstring>
using namespace std;

string str;

int Find_mod(int num)
{
    int l,temp=0;
    l=str.size();
    for(int i=0;i<l;i++)
    {
      temp=temp*10+str[i]-48;
      if(temp/num!=0)
            temp=temp%num;
    }
    return temp;

}

int main()
{
    int check=1;
    int flag,flag1;
    while( getline(cin,str))
    {


        if(check!=1)
            cout<<endl;
            check=2;
        flag=0;
        flag1=0;
        if(Find_mod(4)==0 && (Find_mod(400)==0 || Find_mod(100)!=0))
            flag=1;
        if(flag==1)
            cout<<"This is leap year."<<endl;
        if(Find_mod(15)==0)

           {
            cout<<"This is huluculu festival year."<<endl;
            flag1=1;
           }
        if(flag==1 && Find_mod(55)==0)
        {

            cout<<"This is bulukulu festival year."<<endl;
        }

                if(flag!=1 && flag1!=1)
                    cout<<"This is an ordinary year."<<endl;

    }
    return 0;
}
