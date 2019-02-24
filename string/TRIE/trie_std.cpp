#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Max_node 100010
#define Max_len 101

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

int Find(string str)
{
    int len=str.size();
    int now=root;

    for(int i=0; i<len ; i++)
    {
        if(node[now][str[i]-'a']==-1)
            return 0;
        else
            now=node[now][str[i]-'a'];
    }

    return is_word[now];

}

void print_all(int now,string str)
{
    if(is_word[now])
    {
       cout<<str<<endl;
    }

   for(int i=0; i<26; i++)
   {
       if(node[now][i]!=-1)
        print_all(node[now][i],str+char('a'+i));
   }
}

void print()
{
    string ss;
    ss.clear();
    print_all(root,ss);
}

int main()
{
    int tc;
    scanf("%d",&tc);
    init();


    for(int cs=1 ; cs<= tc ;cs++)
    {

        int n,q;
        cin>>n>>q;

            for(int i=1; i<=n ;i++)
            {
              add();

            }

    }


    return 0;
}
