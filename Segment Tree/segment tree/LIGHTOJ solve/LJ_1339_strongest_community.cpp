#include<iostream>
#include<bits/stdc++.h>
#define Max 100001
#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define sz size()
#define scan(a) scanf("%lld",&a);
#define scani(a) scanf("%d",&a);
#define print(a) printf("%lld\n",a);
#define printi(a) printf("%d\n",a);
#define uu first
#define vv second

using namespace std;


struct node
{
   vector<int>vct;
};

node T[4*Max+1];
int arr[Max+1];

int n;
int K;



///*****[L,R) format , oot starts with 1*****//

void build_cnt(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
       // T[id].vct.clear();
       //cout<<l<<" "<<arr[l]<<endl;
		T[id].vct.push_back(arr[l]);
		return ;
	}
	int mid = (l+r)/2;
	build_cnt(2 * id, l, mid);
	build_cnt(2 * id + 1, mid, r);
	//T[id].vct.clear();
	merge(T[id*2].vct.begin(),T[id*2].vct.end(),T[id*2+1].vct.begin(),T[id*2+1].vct.end(),back_inserter(T[id].vct));
}


/****finds the number greater than k ***/

int ask_cnt(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		{
		    int res=T[id].vct.size()- (upper_bound(T[id].vct.begin(),T[id].vct.end(),K)-T[id].vct.begin());
		    return res;

		}
	int mid = (l + r)/2;
	return ask_cnt(x, y, id * 2, l, mid) +ask_cnt(x, y, id*2+1, mid, r) ;
}





///*****[L,R) format , oot starts with 1*****//

int TM[4*Max+1];
int A[Max+1];

void build_max(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		TM[id] = A[l];
		return ;
	}
	int mid = (l+r)/2;
	build_max(2 * id, l, mid);
	build_max(2 * id + 1, mid, r);
	TM[id] = max(TM[2 * id] , TM[2 * id + 1]);
}

void update_max(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		TM[id] = 0;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update_max(p, 2 * id, l, mid);
	else
		update_max(p, 2 * id + 1, mid, r);
	TM[id] =max(TM[2 * id] , TM[2 * id + 1]);
}




int ask_max(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return TM[id];
	int mid = (l + r)/2;
	return max(ask_max(x, y, id * 2, l, mid),ask_max(x, y, id*2+1, mid, r)) ;
}



int main()
{

    int tc;
    scani(tc);

    map<int,int>mp_ind;
    map<int,int>mp_fre;

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int p;
        scani(p);
        int c;
        scani(c);
        int q;
        scani(q);

        int k=0;

        for(int i=1; i<=p ; i++)
        {
            scani(arr[i]);
            if(mp_ind[arr[i]]!=0)
            {
                mp_ind[arr[i]]=k;
                mp_fre[k]++;

            }
            else
            {
                k++;
                mp_ind[arr[i]]=k;
                mp_fre[k]++;
            }

        }
        for(int i=1; i<=p; i++)
        {
            arr[i]=mp_ind[arr[i]];
           // cout<<arr[i]<<" ";
        }
       // cout<<endl;

        n=k;

        for(int i=1; i<=k ;i++)
            A[i]=mp_fre[i];


         build_cnt(1,1,p+1);
         build_max(1,1,k+1);



         printf("Case %d:\n",cs);

         while(q--)
         {
             int lo,hi;
             scani(lo);
             scani(hi);


             int left=arr[lo];
             int right=arr[hi];

           //  cout<<"left= "<<arr[lo]<<" right="<<arr[hi]<<endl;

             if(left==right)
             {
                 K=left-1;
                 int cnt1=ask_cnt(1,lo,1,1,p+1);

                 int cnt2=ask_cnt(1,hi+1,1,1,p+1);

                // cout<<" cnt1 ="<<cnt1<<" cnt2= "<<cnt2<<endl;
                 int res=cnt2-cnt1;
                 printf("%d\n",res);
             }
             else
             {
                 K=left-1;
                 int cnt1=A[left]-ask_cnt(1,lo,1,1,p+1);
                 K=right-1;
                 int cnt2=ask_cnt(1,hi+1,1,1,p+1);

                 int cnt3=ask_max(left+1,right,1,1,k+1);

                //  cout<<" cnt1 ="<<cnt1<<" cnt2= "<<cnt2<< " cnt3= "<<cnt3<<endl;
                 int res=max(cnt1,cnt2);
                 res=max(res,cnt3);
                 printf("%d\n",res);

             }

         }

         mp_ind.clear();
         mp_fre.clear();

         for(int i=1; i<=Max ; i++)
         {
             T[i].vct.clear();
             TM[i]=0;
         }



    }




    return 0;
}



