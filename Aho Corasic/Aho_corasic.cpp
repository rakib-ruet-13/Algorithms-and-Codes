#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int m, n, res;
typedef pair<int, int> Point;

struct NODE {
    int cnt;
    bool vis;
    NODE *next[27];
    vector <NODE *> out;
    NODE() {
        for(int i = 0; i < 27; i++) {
            next[i] = NULL;
        }
        out.clear();
        vis = false;
        cnt=0;
    }

    ~NODE() {
        for(int i = 1; i < 27; i++)
            if(next[i] != NULL && next[i] != this)
                delete next[i];
    }
}*root;


void init()
{
    root = new NODE();
}

void trie_clear()
{
    delete root;
}

void add(char pattern[])
{
    int len=strlen(pattern);
     NODE *p = root;

       for(int i = 0; i < len; i++)
       {
            char c = pattern[i] - 'a' + 1;
            if(!p->next[c])
                p->next[c] = new NODE();
            p = p->next[c];
       }

}

void build_aho_tree() {


    /** ->next[0] = back Pointer **/

    /** Pushing the nodes adjacent to root into queue **/
    queue <NODE *> q;
    for(int i = 0; i < 27; i++) {
        if(!root->next[i])
            root->next[i] = root;
        else {
            q.push(root->next[i]);
            root->next[i]->next[0] = root;

        }
    }

    /** adding back_edge and dfs tree **/
    while(!q.empty()) {
        NODE *parent = q.front();    // parent node
        q.pop();

        for(int i = 1; i < 27; i++) {
            if(parent->next[i]) {
                NODE *child = parent->next[i];   // child node
                NODE *bp_of_par = parent->next[0];   // back pointer of parent node

                while( !bp_of_par->next[i] )    // Until the char(i+'a'-1) child is found
                    bp_of_par = bp_of_par->next[0];     // go up and up to back pointer.

                child->next[0] = bp_of_par = bp_of_par->next[i];  // back pointer of v will be found child above.
                bp_of_par->out.push_back(child);    // out will be used in dfs step.
                                        // here w is the new found match node.
                q.push(child);              // Push v into queue.
            }
        }
    }
}

void TEXT_PROCESS (NODE *p, char *word) {
       // Third step, processing the text.
    for(int i = 0; word[i]; i++) {
        char c = word[i]-'a'+1 ;
        while(!p->next[c])
            p = p->next[0];
        p = p->next[c];
        p->cnt++;
    }
}

int dfs( NODE *p ) {    // DFS for counting.
    if(p->vis) return p->cnt;
    for(int i = 0; i < p->out.size(); i++)
        p->cnt += dfs(p->out[i]);
    p->vis = true;
    return p->cnt;
}

int Find(char st[])
{
    int len=strlen(st);
    NODE *p = root;
       for(int i = 0; i < len; i++)
       {
            char c = st[i] - 'a' + 1;
            if(!p->next[c])
            {
                return 0;
            }
            else
            p = p->next[c];
       }
       return dfs(p);
}

char text[1010001];
char str[510][510];

int main()
{
    int tc;
    scanf("%d",&tc);

    int n;

    for(int cs=1; cs<=tc ;cs++)
    {
        printf("Case %d:\n",cs);
        scanf("%d",&n);
        scanf("%s",text);

        init();


        for(int i=1; i<=n; i++)
        {
            scanf("%s",str[i]);
            add(str[i]);
        }

        build_aho_tree();
        TEXT_PROCESS(root,text);

        for(int i=1; i<=n; i++)
        {
            printf("%d\n",Find(str[i]));

        }
        trie_clear();

    }

    return 0;


}
