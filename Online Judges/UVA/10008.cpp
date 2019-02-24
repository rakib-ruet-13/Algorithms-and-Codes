#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>

using namespace std;

struct stru
{

    char ch;
    int cnt;
};
bool comp(stru a,stru b);

int main()
{
    static struct stru arr[26],a,b;
    char c;
    long int i,j,n,k;
    cin>>n;
    string str,s;
    c='A';
        for(k=0;k<26;k++)
            {arr[k].ch=c;
            arr[k].cnt=0;
            c++;}
getline(cin,s);
    for(i=0;i<n;i++)
    {

        getline(cin,str);

        for(j=0;j<str.size();j++)
        {

            for(k=0;k<26;k++)
            if((arr[k].ch==str[j]) || (arr[k].ch==str[j]-32))
            {
                arr[k].cnt++;
                break;
            }

        }


    }
    sort(arr,arr+26,comp);

    for(k=0;k<26;k++)
        {
            if(arr[k].cnt==0)
                break;
            cout<<arr[k].ch<<" "<<arr[k].cnt<<endl;
        }

}
bool comp(stru a,stru b)
{

    if(a.cnt>b.cnt)
        return true;
    if(a.cnt==b.cnt && a.ch<b.ch)
    return true;

        return false;
}
