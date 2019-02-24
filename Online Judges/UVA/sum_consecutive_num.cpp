#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int num,n,i;
	double x;
	
	while(cin>>num)
	{
		long int max=-999999;
	   n=1;
	   long int cnt=0;
	   while(((n*(n+1))/2)<=num)
	   {
	   	  x=((double)num-(double)(n*(n-1))/2)/(double)n;
	   	  int d2=ceil(x);
	   	  int d1=floor(x);
	   	  
	   	  if(d1==d2)
	   	   {
	   	   
	   	    	cnt++;
	   	    	if(max<n)
	   	    	max=n;
	   	    	
	   	   	
		   } 
	   	    n++;
	   }
	   cout<<n<<endl;
	   cout<<max<<endl;
	   
	   cout<<cnt<<endl;
		
	}
	return 0;
}
