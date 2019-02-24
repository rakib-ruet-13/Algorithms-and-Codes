#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int sum=0,cs,money;
	string str;
	cin>>cs;
	getchar();
	while(cs--)
	{
		cin>>str;
		if(str[0]!='r')
		{
			cin>>money;
			getchar();
			sum=sum+money;
		}
		else
		cout<<sum<<endl;
	}
	return 0;
}
