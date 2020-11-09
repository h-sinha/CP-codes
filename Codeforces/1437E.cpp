#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
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
typedef	priority_queue<pii, std::vector<pii>, greater<pii> > revpr;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L = 1e6 + 7;
map<ll, ll> counter;
ll fastexpo(ll x, ll y, ll m = 1e9 + 7)
{
	ll temp = 1;
	while (y > 0)
	{
		if (y & 1)temp = ((temp % m) * (x % m)) % m;
		x = ((x % m) * (x % m)) % m;
		y >>= 1;
	} return temp;
}
ll m[L], dp[L], v[L], a[L];
ll CeilIndex(std::vector<ll> &v, ll r, ll key)
{
	return upper_bound(v.begin(), v.begin()+r, key) - v.begin();
}
ll LongestIncreasingSubsequenceLength(ll l, ll r, ll mn, ll mx)
{
	// debug(l,r,mn, mx);
	if (r - l + 1 == 0)return 0;
	std::vector<ll> tail(r - l + 1, 0);
	ll length = 1;
	tail[0] = mn;
	for (int i = l; i <= r; i++) {
		if (a[i] < mn)continue;
		if (a[i] > mx)continue;
		if (a[i] >= tail[length - 1] )
			tail[length++] = a[i];
		else
		{
			tail[CeilIndex(tail, length - 1, a[i])] = a[i];
		}
		// debug(l,r,i,a[i], length);
	}
	// debug(length);
	return length - 1;
}
void fff()
{
	ll n, k;
	cin >> n >> k;
	FOR(i, 0, n)
	{
		cin >> a[i];
		a[i] -= i;
	}
	std::vector<pii> vv;
	int ff = 0;
	FOR(i, 0, k)
	{
		cin >> v[i];
		v[i]--;
		if (!ff && v[0] != 0)
		{
			ff = 1;
			vv.pb({ -1e10, -1});
		}
		m[v[i]] = 1;
		vv.pb({a[v[i]], v[i]});
	}
	if (k == 0)
	{
		vv.pb({ -1e10, -1});
	}
	if (v[k - 1] != n - 1)
	{
		vv.pb({1e9 + 1, n});
	}

	int prv = -1;
	FOR(i, 0, k)
	{
		if (a[v[i]] < prv)
		{
			cout << -1 << ln;
			return;
		}
		prv = a[v[i]];
	}
	int ans = k;
	int mm = sz(vv);
	// debug(mm);
	ll diff;
	FOR(i, 0, mm - 1)
	{
		debug(i,mm);
		diff = LongestIncreasingSubsequenceLength(vv[i].S + 1, vv[i + 1].S - 1, vv[i].F, vv[i + 1].F);
		debug(vv[i].F, vv[i+1].F, vv[i].S, vv[i+1].S, diff);
		ans += diff;
	}
	// debug(n,ans);
	cout << n - ans << ln;
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
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}