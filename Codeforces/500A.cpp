#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
	cin>>n>>t;
	std::vector<int> v(n+1);
	for (int i = 1; i < n; ++i)
		cin>>v[i];
	int i=1;
	while(i<n && i!=t)
			i+=v[i];
	if(i==t)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}