#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int tc,l,i,j,Min;
    long int arr[6];
    string str;
    cin>>tc;
    getchar();
    while(tc--)
    {
        getline(cin,str);
        l=str.size();
        for(i=0;i<6;i++)
            arr[i]=0;
        for(i=0;i<l;i++)
        {
                if(str[i]=='A')
                arr[0]++;

                if(str[i]=='R')
                arr[1]++;

                if(str[i]=='I')
                arr[2]++;

                if(str[i]=='G')
                arr[3]++;

                if(str[i]=='T')
                arr[4]++;

                if(str[i]=='M')
                arr[5]++;


        }
        arr[0]=arr[0]/3;
        arr[1]=arr[1]/2;

        Min=arr[0];
        for(i=1;i<6;i++)
        {
            if(arr[i]<Min)
                Min=arr[i];

        }
        cout<<Min<<endl;
    }

    return 0;
}
