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
int xx = 0;
ll n, m, c[L], dp[L];
bool check(ll val)
{
	ll cur = m;
	FOR(i,0,n)
	{
		if(cur < 0)return 0;
		if(dp[i]<=val)return 1;
		cur--;
	}
	return 1;
}
void fff()
{
	cin >> n >> m;
	FOR(i,0,n)cin >> c[i];
	xx++;
	multiset<ll>SET;
	dp[n-1] = 0;
	SET.insert(0);c[0] = 0;
	RFOR(i,n-2,0)
	{
		if((i==0||c[i]) && !SET.empty())
		{
			dp[i] = c[i] + *SET.begin();
			SET.insert(dp[i]);
		}
		else dp[i] = 1e17;
		if(i+m < n && dp[i+m] != 1e17)
			SET.erase(SET.find(dp[i+m]));
	}
	ll l = 0, r = 1e16, mid;
	while(l<r-1)
	{
		mid = (l+r)/2;
		if(check(mid))r = mid;
		else l = mid;
	}
	if(l<r)swap(l,r);
	if(!check(r))r = l;
	if(!check(r))
	{
		cout << "Case #"<<xx<<": -1"<<ln;
		return;
	}
	cout << "Case #"<<xx<<": "<<r<<ln;
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