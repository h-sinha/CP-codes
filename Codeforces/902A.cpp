#include<bits/stdc++.h>
using namespace std;
int main()
{
	int maximum,m,n,a,f=0;
	cin>>n>>m;
	std::vector<int> v(n+1);
		cin>>a>>v[0];
		if(a!=0)
		{
			cout<<"NO";
			return 0;
		}
		maximum=v[0];
		if(v[0]>=m)
		{
			cout<<"YES";
			return 0;
		}
	for (int i = 1; i < n; i++)
	{
		cin>>a>>v[i];
		if(a>maximum)
		{
			f=0;
			break;
		}
		else if(v[i]>maximum)
			maximum=v[i];
		if(maximum>=m)
		{
			f=1;
			break;
		}

	}
	if(f==1)
		cout<<"YES";
	else
		cout<<"NO";
}