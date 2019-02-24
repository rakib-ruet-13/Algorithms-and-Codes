#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int tc,amp,fre,k,i,j;
    cin>>tc;

    for(int l=1;l<=tc;l++)
    {
        cin>>amp>>fre;
        for(int m=1;m<=fre;m++)
        {
            k=1;
            for(i=1;i<=amp;i++)
            {
                for(j=1;j<=i;j++)
                    cout<<k;
                cout<<endl;
                k++;
            }

            k=k-2;
             for(i=1;i<=amp-1;i++)
            {
                for(j=amp-i;j>0;j--)
                    cout<<k;
                cout<<endl;
                k--;
            }
            if(m!=fre)
            cout<<endl;
            }
            if(l!=tc)
                cout<<endl;
    }

    return 0;
}
