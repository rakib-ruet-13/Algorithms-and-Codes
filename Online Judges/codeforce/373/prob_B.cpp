#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

int main()
{

    string str1,str2;

    int n;
    cin>>n;
    cin>>str1;

    str2=str1;


    //for red

    int r,b;
     int ans=10000000;


     b=r=0;

    for(int i=0 ;i<n ;i++)
    {
        if(i%2==0)
        {
            if(str1[i]=='b')
                b++;
        }
        else
        {
            if(str1[i]=='r')
                r++;

        }
    }


    int res=0;



    if(b>r)
    {
        res+=r;
        res+=(b-r);
    }
     else
    {
        res+=b;
        res+=(r-b);
    }

    ans=min(ans,res);


    b=r=0;

    res=0;

     for(int i=0 ;i<n ;i++)
    {
        if(i%2==0)
        {
            if(str2[i]=='r')
                r++;
        }
        else
        {
            if(str2[i]=='b')
                b++;

        }
    }

    if(b>r)
    {
        res+=r;
        res+=(b-r);
    }
    else
    {
        res+=b;
        res+=(r-b);
    }

    ans=min(res,ans);

    cout<<ans<<endl;







    return 0;
}

