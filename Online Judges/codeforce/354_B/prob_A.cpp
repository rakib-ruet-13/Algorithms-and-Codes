#include<bits/stdc++.h>
#include<iostream>

#define pi acos(-1.000)
#define ll long long
#define rep(i,a,b) for(int i=a; i<=b ;i++)
#define pb push_back


using namespace std;

int main()
{

  int n;
  cin>>n;

  int pos1,pos2;

  for(int i=1;i<=n ;i++)
  {
      int val;
      cin>>val;

      if(val==1)
        pos1=i;

      if(val==n)
        pos2=i;
  }

  if(pos1>pos2)
    swap(pos1,pos2);

  int diff=pos2-pos1;


  cout<<max(pos1-1+diff,diff+(n-pos2))<<endl;





  return 0;
}

