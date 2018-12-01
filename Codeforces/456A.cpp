#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,pos,minprice=INT_MAX,minqual=INT_MAX;
	cin>>n;
	std::vector<int> a(n+1);
	std::vector<int> b(n+1);
	for (int i = 0; i < n; i++)
	{
		cin>>a[i]>>b[i];
		if(float(b[i])/float(a[i])>=float(minqual)/float(minprice))
		{
			minprice=a[i];
			minqual=b[i];
			pos=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i==pos)
			continue;
		if(a[i]>minprice && b[i]<minqual)
		{
			cout<<"Happy Alex";
			return 0;
		}
	}
	cout<<"Poor Alex";
	return 0;
}