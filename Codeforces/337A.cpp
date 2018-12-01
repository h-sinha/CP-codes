#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef long double ld;
int main()
{
	int n,m,mini=INT_MAX;
	cin>>n>>m;
	std::vector<int> f(m);
	FOR(i,0,m)cin>>f[i];
	sort(f.begin(), f.end());
	FOR(i,0,m-n+1)
	{
		if(f[n+i-1]-f[i]<mini)
			mini=f[n+i-1]-f[i];
	}	
	cout<<mini;
	return 0;
}