#include<bits/stdc++.h>
using namespace std;
map <int,int> counter;
int main()
{
	int n,m,num,i;
	cin>>n>>m;
	std::vector<int> v(n+1);
	std::vector<int> ans(n+2);
	for(i=1;i<=n;i++)
		cin>>v[i];
	ans[n+1]=0;
	for(i=n;i>0;i--)
	{
		counter[v[i]]++;
		ans[i]=ans[i+1]+1;
		if(counter[v[i]]>1)
		{
			ans[i]--;
			counter[v[i]]--;
		}
	}
	for(i=1;i<=m;i++)
	{
		cin>>num;
		cout<<ans[num]<<endl;
	}
	return 0;
}