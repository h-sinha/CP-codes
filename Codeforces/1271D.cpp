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
ll a[L], b[L], c[L], co[L], d[L];
ll h[L];
std::vector<int> check;
ll dp[5003][5003];
ll solve(int i, int sofar)
{
	// debug(i,sofar);
	if(i >= sz(check))return 0;
	if(h[check[i]]-sofar < 0)return INT_MIN;
	if(dp[i][sofar] != -1)return dp[i][sofar];
	if(h[check[i]]-sofar-1 < 0)dp[i][sofar] = solve(i+1, sofar);
	else dp[i][sofar] = max(solve(i+1, sofar+1) + c[i], solve(i+1, sofar));
	return dp[i][sofar];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, u, v;
	cin >> n >> m >> k;
	FOR(i,0,n)
		cin >> a[i] >> b[i] >> c[i];
	FOR(i,0,m)
	{
		cin >> u >> v;
		co[v-1]++;
	}
	int f = 0;
	FOR(i,0,n)
	{
		// debug(i,k,a[i]);
		if(k < a[i])
		{
			f = 1;
			break;
		}
		h[i] = k-a[i];
			k += b[i];
		if(co[i] == n-i-1)
		{
			d[i] = 1;
			continue;
		}
		else check.pb(i);
	}
	if(f)
	{
		cout<<-1;
		return 0;
	}	
	if(sz(check) == 0)
	{
		ll ans = 0;
		FOR(i,0,n)
		{
			ans += c[i];
		}
		cout<<ans;
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	RFOR(i,n-2,0)
	{
		h[i] = min(h[i],h[i+1]);
	}
	ll ans = 0;
	FOR(i,0,n)
	{
		if(d[i])ans+=c[i];
	}
	ans += solve(0,0);
	cout<<ans;
	return 0;
}