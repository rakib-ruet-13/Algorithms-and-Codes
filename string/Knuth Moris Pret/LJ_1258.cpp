#include<iostream>
#include<bits/stdc++.h>
#define Max 2001000

using namespace std;

int pi[Max];
string P;
string T;
int cnt[Max]; /** counting all prefix as substring **/

typedef long long ll;

/**P#T count***/
int failure_cnt;
int prefix_size;

/*** for unique substring***/
int max_match;



int prefix_fun()
{
    failure_cnt=0; /**** Needed for P#T */
    max_match=-1;

    int now;
    pi[0]=now=-1;

    int len=P.size();

    for(int i=1; i<len ; i++)
    {
        while(now!=-1 && P[now+1]!=P[i])
            now=pi[now];
        if(P[now+1]==P[i])
            pi[i]=++now;
        else
            pi[i]=now=-1;

        max_match=max(max_match,now);

        if(now==prefix_size-1)
            failure_cnt++;
    }
}




int kmp_match()
{
     int now=-1;
    int n=T.size();
    int m=P.size();



    for(int i=0; i<n ; i++)
    {
        while(now!=-1 && P[now+1]!=T[i])
            now=pi[now];

        if(P[now+1]==T[i])
            ++now;
        else
            now=-1;


        if(i==n-1)
        {
            return now;
        }
    }
    return 0;


}



int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {
        cin>>T;
        P=T;
        reverse(P.begin(),P.end());
        int len=P.size();

        prefix_fun();
        printf("Case %d: %d\n",cs,2*len-kmp_match()-1);

    }
    return 0;
}



