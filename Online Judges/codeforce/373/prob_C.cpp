#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

int main()
{

    int n,t;

    string str,ss,ii;

    cin>>n;
    cin>>t;

    cin>>str;


    for(int i=0 ; i<n ;i++)
    {
        if(str[i]=='.')
        {
            for(int j=0; j<i ;j++)
            {
               ii+=str[j];
            }

           for(int j=i+1;j<n ;j++)
           {
              ss+=str[j];
           }
           break;
        }
    }

    int carry1;
    carry1=0;

    int pos=-1;

    //cout<<ii<<" "<<ss<<endl;

    bool flag=1;
    for(int i=0 ;i<ss.size() && flag ;i++)
    {
        if(ss[i]>='5' && i==0)
        {
            carry1++;
            pos=0;
            flag=0;
            break;
        }

        if(ss[i]>='5' )
        {
            ss[i-1]+=1;
            t--;
            pos=i-1;
            flag=0;
        }


        for(int j=i-1; j>=0 && t>0 ; j--)
        {
            if(ss[j]>='5')
            {
                if(j==0)
                {
                    carry1++;
                    pos=0;
                    break;
                }

                ss[j-1]++;
                t--;
                pos=j-1;
            }
            else
            {
                break;
            }

        }




    }

    //cout<<ii<<" "<<ss<<" cr"<<carry1<<endl;

    if(pos==-1)
        cout<<str<<endl;
    else if(carry1==1)
    {
        int c=1;

        for(int j=ii.size()-1 ; j>=0 ;j--)
        {
            if(ii[j]+c > '9')
            {
                ii[j]='0';
                c=1;

            }
            else
            {
                ii[j]++;
                c=0;
                break;
            }
        }
        if(c==1)
            {
                cout<<1<<ii<<endl;
            }
        else
        {
            cout<<ii<<endl;
        }
    }
    else
    {
        cout<<ii<<".";

        for(int p=0; p<=pos; p++)
        {
            cout<<ss[p];
        }
        cout<<endl;
    }



    return 0;
}
