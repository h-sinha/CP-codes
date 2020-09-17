#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n,pos,t;
	cin>>n;
	std::vector<int> c(n+1);
	std::vector<int> s(n+1);
	std::vector<int> f(n+1);
	std::vector<int> ans(n+1);
	for (int i = 0; i < n-1; i++)
		cin>>c[i]>>s[i]>>f[i];
	for (int i = 0; i < n-1; i++)
	{
		pos=i;
		t=s[i]+c[i];
		pos++;
		while(pos!=n-1)
		{
			while((t-s[pos])%f[pos]!=0 || t<s[pos])
				t++;
			t+=c[pos];
			pos++;
 
		}
		ans[i]=t;
	}
	for (int i = 0; i < n; i++)
		cout<<ans[i]<<endl;
	return 0;
}