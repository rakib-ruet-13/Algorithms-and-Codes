#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string rev(int num)
{
    string st;
	int n=0;
	while(num)
	{
		st+=char(num%10+48);
		num=num/10;

	}
	//cout<<st;
	return st;
}



int main()
{
	string str;

	while(getline(cin,str))
	{
		reverse(str.begin(),str.end());
		int val=0;
		for(int i=0;i<str.size();i++)
        {
		if(str[i]>='0' && str[i]<='9')
		{




              val=val*10+	((int)str[i]-48);


			{
				if(val>18)
			    {
			    	cout<<char(val);
			    	val=0;
				}


			}

		}
		else
		{

			{
				cout<<rev(int(str[i]));
			}
		}
        }
		cout<<endl;
		str.clear();
	}
	return 0;

}

