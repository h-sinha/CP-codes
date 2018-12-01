#include<bits/stdc++.h>
using namespace std;
std::vector<bool> visit(101,0);
std::vector<int> x(101);
std::vector<int> y(101);
void dfs(int v);
int n;
int main()
{
	int ans=-1;
	cin>>n;
	for (int i = 1; i <=n; i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==0)
		{
			ans++;
			dfs(i);
		}
	}
	cout<<ans;
	return 0;
}
void dfs(int v)
{
	visit[v]=1;
	for (int i =1; i <=n; i++)
	{
		if((x[i]==x[v] || y[i]==y[v]) && visit[i]==0)
			dfs(i);
	}
}