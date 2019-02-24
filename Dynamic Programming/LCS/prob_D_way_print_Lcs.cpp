#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char str1[101],str2[101];
string ans;
int pre;
int l1,l2;
struct node
{
    string st;
    int val;
};

node  dp[110][110];

int lcs(int i,int j,string st,int carry)
{
    if(i>=l1 || j>=l2)
    {
        return 0;
    }
    if(dp[i][j].val!=-1)
    {
        return dp[i][j].val;
    }

    if(str1[i]==str2[j])
    {

        carry+=1;
        return dp[i][j].val=1+lcs(i+1,j+1,st,carry);
        st+=str1[i];


    }
    else
    {
        int res1=lcs(i,j+1,st,carry);
        int res2=lcs(i+1,j,st,carry);

        return dp[i][j].val=max(res1,res2);

    }


}



int main()
{

    int tc;

    scanf("%d",&tc);
    getchar();

    string st;

    for(int cs=1 ; cs<= tc ; cs++)
    {

        cin>>str1;
        cin>>str2;

        l1=strlen(str1);
        l2=strlen(str2);



          for(int i=0; i<=l1 ;i++)
            for(int j=0; j<=l2 ;j++)

         {
             dp[i][j].st.clear();
             dp[i][j].val=-1;

         }
        st.clear();

        pre=0;
        int len=lcs(0,0,st,0);

       // cout<<len<<endl;

        if(len==0)
        {
            printf("Case %d: :(\n",cs);
        }
        else
        {
             printf("Case %d: ",cs);
             cout<<ans<<endl;

        }
        ans.clear();
    }

    return 0;
}

