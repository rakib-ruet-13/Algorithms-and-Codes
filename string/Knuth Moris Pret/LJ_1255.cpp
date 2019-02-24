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

long long unique_substring(string str);
int prefix_fun();
int kmp_match();
long long cnt_all_prefix_match();
int concate(string str);

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



int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {
       cin>>T;
       cin>>P;

       prefix_size=P.size();

       P+='#';
       P+=T;
       prefix_fun();

       printf("Case %d: %d\n",cs,failure_cnt);



    }
    return 0;
}



