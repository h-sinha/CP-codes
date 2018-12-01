#include<bits/stdc++.h>
using namespace std;
std::map<int,int> counter;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	std::vector<int> a(m+1);
	std::vector<int> b(m+1);
	std::vector<int> wt(m+1);
	for (int i = 1; i <=m; i++)
		cin>>a[i]>>b[i]>>wt[i];
	if(k==0)
	{
		cout<<"-1";
		return 0;
	}
	int num;
	for (int i = 0; i <k; i++)
	{
		cin>>num;
		counter[num]++;
	}
	int minimum=INT_MAX;
	for (int i = 1; i <=m; i++)
	{
		if((counter[a[i]]!=0 && counter[b[i]]==0) ||(counter[b[i]]!=0 && counter[a[i]]==0))
		{
			if(wt[i]<minimum)
				minimum=wt[i];
		}
	}
	if(minimum==INT_MAX)
		cout<<"-1";
	else
		cout<<minimum;

}