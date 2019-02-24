#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define vi vector<int>
#define  LL  long long
#define inf 1<<29
#define fr first
#define sc second
#define M 60020

int Lazy[M<<3],Tree[M<<3],A[M];

class ST{
    private :

    int n;
        // no building
    void update(int p,int L,int R,int i,int j,int flag) // O(lg n )
        {
            if(A[L]>j   ||  A[R]<i) return;
            if(A[L]>=i   &&   A[R]<=j)  // if in range then check the flag
                // if flag=true then we have to add the interval else delete
            {
                if(flag == 1)
                    Lazy[p]++;
                    else Lazy[p]--;
                    if(Lazy[p])
                        Tree[p]=A[R]-A[L]; // when [2,4] it means it has length 2 not 3
                    else Tree[p]=Tree[p<<1]+Tree[(p<<1)  +1];// there is zero means we close it now and all interval cover this are eliminated , now we need to consider the child
                return;
            }
            if(L+1      >=R) return; // we skip length 1 interval
            update(p<<1,L,(L+R)>>1,i,j,flag);
            update((p<<1)   +1,(L+R)>>1,R,i,j,flag); //that is the special part , not mid+1 ,real mid ,like from {0->2} to {0->1,1->2}
            // because no interval will be < 1 ,that will become a point then.
            // and also there must be the ending point in the list
                    if(Lazy[p])
                        Tree[p]=A[R]-A[L];
                    else Tree[p]=Tree[p<<1]+Tree[(p<<1)  +1];
            return;
        }
    public:
        ST(int a)
        {
            n=a;
            for(int i=0;i<=  8*M;i++) // it is not usual segment tree . it uses extra space so we need double space then ST
              {

              Lazy[i]=0;Tree[i]=0;}
        }
        void update(int i,int j,int flag)
        {
            update(1,1,n,i,j,flag);
        }

};

    int main()
    {
        int T,I=1;
        cin>>T;

        vector<pair<pair<int,int>,pair<int,int> > > E;
        while(T--)
        {
            E.clear();
            printf("Case %d: ",I++);

            int n;
            scanf("%d",&n);

            int a,b,c,d;
            int k=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d %d %d %d",&a,&b,&c,&d);
                E.push_back(make_pair(make_pair(a,1),make_pair(b,d)));
                E.push_back(make_pair(make_pair(c,0),make_pair(b,d)));
                A[++k]=b;
                A[++k]=d;

            }
            sort(E.begin(),E.end());

            sort(A+1,A+k+1);

            int j=1;
            for(int i=2;i<=k;i++)
                if(A[i]!=A[j])
                    A[++j]=A[i];

                k=j;

            ST B(k);

            LL res=0;

            B.update(E[0].sc.fr,E[0].sc.sc,E[0].fr.sc);

            for(int i=1;i< E.size();i++)
            {
                res+=(Tree[1]*  (LL)(E[i].fr.fr-E[i-1].fr.fr));
                B.update(E[i].sc.fr,E[i].sc.sc,E[i].fr.sc);
            }

            printf("%lld\n",res);
        }
        return 0;}

