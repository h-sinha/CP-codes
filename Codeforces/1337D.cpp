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
ll get(ll x, ll y, ll z)
{
	ll ans = (x-y)*(x-y);
	ans += (y-z)*(y-z);
	ans += (z-x)*(z-x);
	return ans;
}
ll solve(std::vector<ll> &a, std::vector<ll> &b, std::vector<ll> &c)
{
	std::vector<ll>::iterator it1;
	std::vector<ll>::iterator it2;
	std::vector<ll>::iterator it3;
	std::vector<ll>::iterator it4;
	std::vector<ll>::iterator it5;
	std::vector<ll>::iterator it6;
	ll ans = LLONG_MAX;
	trace(a,x)
	{
		it1 = lower_bound(all(b), x);
		it2 = it1;
		if(it1 != b.begin())it1--;
		else it1 = b.end();
		
		it3 = lower_bound(all(c), x);
		it4 = it3;
		if(it3 != c.begin())it3--;
		else it3 = c.end();
		
		if(it1 != b.end() && it3 != c.end())
		ans = min(ans, get(x, *it1, *it3));
		if(it1 != b.end() && it4 != c.end())
		ans = min(ans, get(x, *it1, *it4));
		if(it2 != b.end() && it3 != c.end())
		ans = min(ans, get(x, *it2, *it3));
		if(it2 != b.end() && it4 != c.end())
		ans = min(ans, get(x, *it2, *it4));
		if(it1 != b.end())
		{
			it3 = lower_bound(all(c), *it1);
			it4 = it3;
			if(it3 != c.begin())it3--;
			else it3 = c.end();

			if(it3 != c.end())
			ans = min(ans, get(x, *it1, *it3));
			if(it4 != c.end())
			ans = min(ans, get(x, *it1, *it4));
			if(it3 != c.end())
			ans = min(ans, get(x, *it1, *it3));
			if(it4 != c.end())
			ans = min(ans, get(x, *it1, *it4));
		}
		if(it2 != b.end())
		{
			it3 = lower_bound(all(c), *it2);
			it4 = it3;
			if(it3 != c.begin())it3--;
			else it3 = c.end();

			if(it3 != c.end())
			ans = min(ans, get(x, *it2, *it3));
			if(it4 != c.end())
			ans = min(ans, get(x, *it2, *it4));
			if(it3 != c.end())
			ans = min(ans, get(x, *it2, *it3));
			if(it4 != c.end())
			ans = min(ans, get(x, *it2, *it4));
		}
	}
	return ans;
}
void fff()
{
	ll nr, ng, nb;
	cin >> nr >> ng >> nb;
	std::vector<ll> a(nr), b(ng), c(nb);
	FOR(i,0,nr)cin >> a[i];
	FOR(i,0,ng)cin >> b[i];
	FOR(i,0,nb)cin >> c[i];
	sort(all(a));
	sort(all(b));
	sort(all(c));
	
	ll ans = LLONG_MAX;
	ans = min(ans, solve(a, b, c));
	ans = min(ans, solve(a, c, b));
	ans = min(ans, solve(b, a, c));
	ans = min(ans, solve(b, c, a));
	ans = min(ans, solve(c, a, b));
	ans = min(ans, solve(c, b, a));
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}