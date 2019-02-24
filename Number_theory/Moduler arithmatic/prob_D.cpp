#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Max_node 1000100
#define Max_len 101000

string st;
char S[Max_len];
int node[Max_node][26];
int root;
int nnode;
int is_word[Max_node];

void init()
{
    root=0;
    nnode=0;
    for(int i=0; i<26; i++)
        node[root][i]=-1;
    memset(is_word,0,sizeof(is_word));
}

void add()
{
    scanf("%s",S);
    int len=strlen(S);

    int now=root;

    for(int i=0; i<len; i++)
    {
        if(node[now][S[i]-'a']==-1)
        {
            node[now][S[i]-'a']=++nnode;
            for(int k=0; k<26; k++)
            {
                node[nnode][k]=-1;
            }
        }
        now=node[now][S[i]-'a'];
         is_word[now]++;

    }

}

long long Find(string str)
{
    int len=str.size();
    int now=root;

    long long sum=0;

    for(int i=0; i<len ; i++)
    {
        if(node[now][str[i]-'a']==-1)
            return sum;
        else
            now=node[now][str[i]-'a'];

            sum+=is_word[now];
    }

    return sum;

}


int main()
{
   // int tc;
    //scanf("%d",&tc);
    init();



        int n,q;
        cin>>n>>q;

            for(int i=1; i<=n ;i++)
            {
              add();

            }
            long long res=0;

            while(q--)
            {
                string str;
                cin>>str;
                res+=Find(str);

            }
            cout<<min(res,(long long)n)<<endl;




    return 0;
}

