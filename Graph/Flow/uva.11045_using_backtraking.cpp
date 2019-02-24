#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int t_shirt[6];

vector< pair<int,int> >person;
int n,tot;

int check(string str)
{
    int val;

    if(str=="XXL")
        val=0;
   if(str=="XL")
        val=1;
    if(str=="L")
        val=2;
    if(str=="M")
        val=3;
    if(str=="S")
        val=4;
    if(str=="XS")
        val=5;
    return val;

}


bool solve(int pos,int arr[])
{

    //cout<<pos<<endl;

    if(pos==n)
        return true;

     int u=person[pos].first;
     int v=person[pos].second;


     bool res1=false;
     bool res2=false;

    // cout<<"pos="<<pos<<"arr["<<u<<"]="<<arr[u]<<" shirt[u]= "<<t_shirt[u]<<endl;

     if(arr[u]+1<=t_shirt[u])
     {
         arr[u]++;

         res1= res1 || solve(pos+1,arr);
         arr[u]--;
     }

     if(arr[v]+1<=t_shirt[v])
     {
         arr[v]++;
         res2=res2 || solve(pos+1,arr);
         arr[v]--;
     }

     return (res1|| res2);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>tot;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            string str1,str2;

            cin>>str1>>str2;

            int u,v;
            u=check(str1);
            v=check(str2);

            person.push_back(make_pair(u,v));
        }

        for(int i=0; i<6;i++)
        {
            t_shirt[i]=(tot/6);
        }

        int arr[6];

        for(int i=0; i<6;i++)
            arr[i]=0;

        if(solve(0,arr))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        person.clear();

    }
}
