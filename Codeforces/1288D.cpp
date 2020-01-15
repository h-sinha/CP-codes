#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
 
const int L=1e6+7;
ll a[L][10], n, m, po[11], ansx = 1, ansy = 1;
bool check(ll x)
{
	int co[po[m]]{};
	co[0] = 1;
	std::vector<ll> v(n);
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if(a[i][j] >= x)v[i] |= po[j];
		}

		if(co[po[m]-1-v[i]])
		{
			ansx = i+1;
			ansy = co[po[m]-1-v[i]];
			return 1;
		}
		co[v[i]] = i+1;
		for (ll s = v[i];s=(s-1)&v[i];)
		{
			co[s] = i+1;
			if(!s)break;
		}
	}
	return 0;
}
void solve()
{
	po[0] = 1;
	FOR(i,1,11)po[i] = po[i-1]<<1;
	cin >> n >> m;
	FOR(i,0,n)
		FOR(j,0,m)
			cin >> a[i][j];
	ll l = 0, r = 1e9, mid;
	while(l<r-1)
	{
		mid = (l+r)/2;
		if(check(mid))l = mid;
		else r = mid;
	}
	if(!check(r))r = l;
	cout<<ansx<<" "<<ansy;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	solve();
	return 0;
}
