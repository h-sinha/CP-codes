#include<bits/stdc++.h>
using namespace std;
int main()
{
	int f,m,s,mas;
	cin>>f>>m>>s>>mas;
	if(s>mas)
	{
		if(2*mas<s || mas>=m)
		{
			cout<<"-1";
			return 0;
		}
		cout<<2*f<<endl;
		cout<<2*m<<endl;
		cout<<s<<endl;
		return 0;
	}
	if(2*s<mas || mas>=m)
		{
			cout<<"-1";
			return 0;
		}
		cout<<2*f<<endl;
		cout<<2*m<<endl;
		cout<<mas<<endl;
			return 0;
	return 0;
}