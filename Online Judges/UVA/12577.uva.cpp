#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str1,str2,str;
	str1="Hajj";
	str2="Umrah";
	int cs=0;
	
	while(cin>>str)
	{
		if(str1==str)
		{
			printf("Case %d: Hajj-e-Akbar\n",++cs);
		}
		else if(str2==str)
		{
			printf("Case %d: Hajj-e-Asghar\n",++cs);
		}
		else
		break;
		
	}
	return 0;
}
