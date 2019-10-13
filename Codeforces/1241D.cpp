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
#define sz(a)	int(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
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
int a[L];
std::vector<int> mn(L), mx(L), dp(L);
void solve()
{
	int n;
	cin >> n;
	set<int>SET;
	fill(mn.begin(), mn.begin()+n+1,INT_MAX);
	fill(mx.begin(), mx.begin()+n+1,INT_MIN);
	fill(dp.begin(), dp.begin()+n+1,0);
	FOR(i,0,n)
	{
		cin >> a[i];
		SET.insert(a[i]);
		mn[a[i]] = min(mn[a[i]], i);
		mx[a[i]] = max(mx[a[i]], i);
	}
	std::vector<int> v;
	trace(SET,x)v.pb(x);
	int ans = n;
	dp[0] = 1;
	FOR(i,1,sz(v))
	{
		if(mn[v[i]] <= mx[v[i-1]])dp[i] = 1;
		else dp[i] = dp[i+1] + 1;
		ans = min(ans, sz(v) - dp[i]);
	}
	fill(dp.begin(), dp.begin()+n+1,0);
	RFOR(i,sz(v)-1,0)
	{
		if(i == sz(v)-1 || mx[v[i]] >= mn[v[i+1]])dp[i] = 1;
		else dp[i] = 1 + dp[i+1];
		ans = min(ans, sz(v)-dp[i]);
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while(q--)solve();
	return 0;
}
