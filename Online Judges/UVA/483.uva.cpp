#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str,st;
	long int i,l;
	
	while(getline(cin,str))
	{
		l=str.size();
		for(i=0;i<l;i++)
		{
			if(str[i]!=' ')
			 st+=str[i];
			else
			{
				reverse(st.begin(),st.end());
				cout<<st<<" ";
				st.clear();
			}
			
		}
		reverse(st.begin(),st.end());
		cout<<st<<endl;
		st.clear();
		
	}
}
