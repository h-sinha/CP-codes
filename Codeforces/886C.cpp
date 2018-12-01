#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define L 1e5
#define pb push_back
typedef long long ll;
typedef long double ld;
//std::map<int, int> counter;
int counter[200002],modu=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,ans=0,f=0;
	cin>>n;
	std::vector<int> v(n);
	FOR(i,0,n)
	{
		cin>>v[i];
		counter[v[i]]++;
	}
	FOR(i,0,200001)
	{
		if(counter[i]>0)
		ans+=(counter[i]-1);
	}
	cout<<ans+1;
	return 0;
}