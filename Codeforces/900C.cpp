#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,pos,prev,n,max;
	cin>>n;
	vector <int> v(n+1);
	vector <int> ans(n+1);
	prev=n;
	max=0;
	for(i=0;i<n;i++)
	{
		cin>>v[i];
		if(v[i]>v[max])
		{
			ans[i]--;
			prev=max;
			max=i;
		}
		else if(v[i]==v[max])
			ans[i]--;
		else if(v[i]<v[max] && v[i]>v[prev])
		{
			ans[max]++;
			prev=i;
		}
	}
	pos=0;
	for(i=0;i<n;i++)
	{
		if(ans[i]>ans[pos])
			pos=i;
		else if(ans[i]==ans[pos] && v[i]<v[pos])
			pos=i;
	}
	cout<<v[pos]<<endl;
	return 0;

}