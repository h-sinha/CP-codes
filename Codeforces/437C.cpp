#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	std::vector<int> cost(n+1);
	for (int i = 1; i <=n; i++)
		cin>>cost[i];
	int u,v;
	for (int i = 0; i <m; i++)
	{
		cin>>u>>v;
		ans+=min(cost[u],cost[v]);
	}
	cout<<ans;
	return 0;
}