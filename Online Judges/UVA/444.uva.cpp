#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int rev(int num)
{
	int n=0;
	while(num)
	{
		n=n*10+num%10;
		num=num/10;

	}
	return n;
}



int main()
{
	string str;

	while(getline(cin,str))
	{
		reverse(str.begin(),str.end());
		if(str[0]>='0' && str[0]<='9')
		{
			cout<<str<<endl;

			int val=0;
			for(int i=0;i<str.size();i++)

			{
				cout<<str[i]<<endl;
				if(val<32)
				{
					val=val*10+	((int)str[i]-48);
					cout<<val<<endl;
				}

			    else
			    {
			    	cout<<char(val);
			    	val=str[i]-48;
				}
				//cout<<val<<"***"<<endl;


			}
		}
		else
		{
			for(int i=0;i<str.size();i++)
			{
				cout<<rev(int(str[i]));
			}
		}
		cout<<endl;
		str.clear();
	}
	return 0;

}
