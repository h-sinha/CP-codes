#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,x,a,ans=0;
	cin>>n>>x;
	FOR(i,0,n)
	{
		cin>>a;
		ans+=counter[a^x];
		counter[a]++;
	}
	cout<<ans;
	return 0;
}