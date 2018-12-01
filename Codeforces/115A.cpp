#include<bits/stdc++.h>
using namespace std;
vector<bool> visited(2001, false);
vector<int> v[2001];
int func(int vertex);
int main()
{
	int pos[2000],n,num,k=0,maximum=-INT_MAX;
	cin>>n;
	for (int i = 1; i <=n; i++)
	{
		cin>>num;
		if(num!=-1)
		{
			v[num].push_back(i);
			v[i].push_back(num);
		}
		else
		{
			pos[k]=i;
			k++;
		}
	}
	for(int i=0;i<k;i++)
	{
			int temp=func(pos[i]);
			if(temp>maximum)
				maximum=temp;
	}
	if(maximum==-INT_MAX)
		cout<<"1";
	else
		cout<<maximum;
	return 0;
}
int func(int vertex)
{
	if(visited[vertex])
		return 0;
	visited[vertex]=1;
	int m=-INT_MAX;
	for (int i = 0; i < v[vertex].size();i++)
	{
		int ans=0;
		ans+=(1+func(v[vertex][i]));
		if(ans>m)
			m=ans;
	}
	return m;
}