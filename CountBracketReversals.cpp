#include<bits/stdc++.h>
using namespace std;
int countBracketReversals(string str)
{
	if(str.length()&1)
	{
		return -1;
	}
	stack<char> s;
	double count=0;
	int res;
	// Removing balanced bracket
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='}')
		{
			if(!s.empty() && s.top()=='{')
			{
				s.pop();
			}
			else
			{
				s.push(str[i]);
			}
		}
		else
		{
			s.push(str[i]);
		}
	}
	// stack only contain }}}}{{{.. like elements as we remove all balanced brackets
	while(!s.empty() && s.top()=='{')
	{
		count++;
		s.pop();
	}
	// count keeps count of { this bracket
	// now stack only contains }}}} this type of brackets;
	res=ceil(count/2) + ceil(double(s.size())/2); // ceil takes double in argument
	return res;
}
int main()
{
	string str;
	cin>>str;
	int k=countBracketReversals(str);
	cout<<k<<endl;
}
