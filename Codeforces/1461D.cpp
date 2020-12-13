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
#define eb emplace_back
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
ll dp[L];
set<ll>SET;
ll cs(ll l, ll r)
{
	if(l == 0)return dp[r];
	return dp[r] - dp[l-1];
}
void pre(int l, int r, std::vector<ll> &a)
{
	if(l == r)
	{
		SET.insert(a[l]);
		return;
	}
	if(l > r)return;
	SET.insert(cs(l,r));
	ll mid = (a[r] + a[l])/2;
	int it = upper_bound(a.begin(), a.end(), mid) - a.begin();
	if(it > r)return;
	pre(l, it-1, a);
	pre(it, r, a);
}
void fff()
{
	int n, q;
	cin >> n >> q;
	std::vector<ll> a(n);
	FOR(i,0,n)cin >> a[i];
	sort(all(a));
	FOR(i,0,n)dp[i] = a[i];
	FOR(i,1,n)dp[i] += dp[i-1];
	SET.clear();
	pre(0, n-1, a);
	ll x;
	FOR(i,0,q)
	{
		cin >> x;
		if(SET.find(x) != SET.end())cout << "Yes\n";
		else cout << "No\n";
	}
}
int main()
{
	#ifdef LOCAL_EXEC
	  freopen("in.txt", "r", stdin);
	  freopen("out.txt", "w", stdout);
	#else
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	#endif
	int t;cin >> t;while(t--)
	fff();
	return 0;
}