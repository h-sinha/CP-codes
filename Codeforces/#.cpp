#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int sum=0,n;
	cin>>n;
	std::vector<long long int> v1(n+1);
	std::vector< long long int> v2(n+1);
	for (int i = 1; i <=n; i++)
	{	cin>>v1[i];
		sum+=v1[i];
	}
	for (int i = 1; i <= n; i++)
		cin>>v2[i];
	sort(v2.begin(),v2.end());
	for(int i=1;i<n;i++)
	{
		if(v2[i]+v2[i+1]>=sum)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}