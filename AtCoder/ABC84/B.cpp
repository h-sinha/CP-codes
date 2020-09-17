#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int a,b;
	char s[100];
	cin>>a>>b;
	cin>>s;
	if(s[a]!='-')
	{
		cout<<"No";
		return 0;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		if(i==a)
			continue;
		if(s[i]-'0'<0||s[i]-'0'>9)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int a,b;
	char s[100];
	cin>>a>>b;
	cin>>s;
	if(s[a]!='-')
	{
		cout<<"No";
		return 0;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		if(i==a)
			continue;
		if(s[i]-'0'<0||s[i]-'0'>9)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
