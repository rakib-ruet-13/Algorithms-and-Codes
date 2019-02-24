#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    bool endmark;
    node *next[11];

    node()
    {
        for(int i=0;i<10;i++)
            next[i]=NULL;
        endmark=false;
    }
}*root;

bool insert_trie(string str)
{
    node *curr=root;
    int len=str.size();

    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';

         if(curr->next[id]==NULL)
            curr->next[id]=new node();
        else if(i==len-1)
           {
               //cout<<"in"<<endl;
               return true;
           }

           if(curr->endmark==true)
            return true;

         curr=curr->next[id];
    }

    if(curr->endmark==true)
            return true;

    curr->endmark=true;
    return false;

}



void del(node *curr)
{
    for(int i=0;i<10;i++)
    {
        if(curr->next[i])
          del(curr->next[i]);
    }
    free(curr);
}

int main()
{


    string str;


    int n,tc;
    cin>>tc;
    while(tc--)
    {

        root=new node();
        bool flag=false;
        cin>>n;
        getchar();


       for(int i=0;i<n;i++)
       {
           cin>>str;

           if(!flag)
            flag=insert_trie(str);


       }

    if(!flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


        str.clear();

       del(root);
    }


   return 0;

}

