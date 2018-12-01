#include<bits/stdc++.h>
using namespace std;
int m,f=0;
std::vector<int> mem(20002);
int func(int n);
int main()
{
	int n,ans=0;
	cin>>n>>m;
	if(n>m)
	{
		cout<<n-m;
		return 0;
	}
	while(m!=n)
	{
		if(m%2==0 && m>n)
		{
			m/=2;
			ans++;
		}
		else
		{
			m++;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}