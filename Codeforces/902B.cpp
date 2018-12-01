#include<bits/stdc++.h>
using namespace std;
int ans=0,n,num;
void func(int vertex,int color);
vector<bool> visited(10002,false);
std::vector<int> v[10002];
std::vector<int> c(10002);
int main()
{
	cin>>n;
	for (int i = 2; i <= n; i++)
	{
		cin>>num;
		v[i].push_back(num);
		v[num].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin>>c[i];
	func(1,0);
	cout<<ans;
	return 0;
}
void func(int vertex,int color)
{
	if(visited[vertex])
		return;
	visited[vertex]=true;
	if(color!=c[vertex])
		ans++;
	for(int i=0;i<v[vertex].size();i++)
	{
		func(v[vertex][i],c[vertex]);
	}

}