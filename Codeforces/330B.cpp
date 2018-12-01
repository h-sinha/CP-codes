#include<bits/stdc++.h>
using namespace std;
std::map<int,int> counter;
int main()
{
	int n,m,start,minimum=INT_MAX;
	cin>>n>>m;
	std::vector<int> a(n+1);
	std::vector<int> b(n+1);
	for (int i = 0; i <m; i++)
	{
		cin>>a[i]>>b[i];
		counter[a[i]]++;
		counter[b[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(counter[i]<minimum)
		{
			minimum=counter[i];
			start=i;
		}
	}
	if(minimum==0)
	{
		cout<<n-1<<endl;
		for (int i = 1; i <=n; i++)
		{
			if(i==start)
				continue;
			else
				cout<<start<<" "<<i<<endl;
		}
		return 0;
	}
	
	return 0;
}