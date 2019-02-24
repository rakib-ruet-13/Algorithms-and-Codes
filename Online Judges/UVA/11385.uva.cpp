#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    long long int fibo[500],i,j,k,tc,num[101],n,l1,m,maX,val;
    string str1,str,str3;
    char st[101];

    fibo[0]=1;
    fibo[1]=1;
    for(i=2; ;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
        if(fibo[i]>100000000000)
        {
            break;
        }

    }

    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(j=0;j<n;j++)
            cin>>num[j];

            getline(cin,str3);
            getline(cin,str1);

            l1=str1.size();

             for(i=0;i<101;i++)
                st[i]=' ';

                 j=0;
                maX=-1111;
            for(i=0;i<l1;i++)
            {
                if(j==n)
                    break;

                if('A'<=str1[i] && str1[i]<='Z')
                {
                    for(int z=1; z<55;z++)
                    {
                        if(num[j]==fibo[z])
                        {
                           val=z;
                           if(val-1>maX)
                                maX=val-1;
                                j++;
                           break;
                        }
                    }
                     st[val-1]=str1[i];

                }

            }

           for(i=0;i<=maX;i++)
                cout<<st[i];
            cout<<endl;



    }
    return 0;
}


