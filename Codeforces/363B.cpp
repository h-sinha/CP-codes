#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,max=-INT_MAX,i,pos;
	cin>>n>>k;
	std::vector<int> v(n+1);
	std::vector<int> cum(n+1);
	for (int i = 1; i <=n; i++)
		cin>>v[i];
	cum[1]=v[1];
	for (int i = 2; i <=n; i++)
		cum[i]=cum[i-1]+v[i];
	max=cum[k];
	pos=k;
	for(i=k+1;i<=n;i++)
	{
		if((cum[i]-cum[i-k])<=max)
		{
			max=cum[i]-cum[i-k];
			pos=i;
		}
	}
	cout<<pos-k+1<<endl;
	return 0;
}