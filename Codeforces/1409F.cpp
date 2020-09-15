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
const int L=2e2+7;
string s, t;
ll n, k, dp[L][L][L];
// idx, t[0] count, changes sofar
ll solve(int i, int c0, int sofar)
{
	if(sofar > k)return -1e6;
	if(i == n)return 0;
	if(dp[i][c0][sofar] != -1)return dp[i][c0][sofar];
	ll &ret = dp[i][c0][sofar];
	if(s[i] == t[0])
	{
		// no change
		ret = max(ret, solve(i+1, c0 + 1, sofar));
		// change to t1
		ret = max(ret, c0 + solve(i+1, c0, sofar + 1));
	}
	else if(s[i] == t[1])
	{
		// no change
		ret = max(ret, c0 + solve(i+1, c0, sofar));
		// change to t0
		ret = max(ret, solve(i+1, c0 + 1, sofar + 1));
	}
	else
	{
		// no change
		ret = max(ret, solve(i+1, c0, sofar));
		// change to t0
		ret = max(ret, solve(i+1, c0 + 1, sofar + 1));
		// change to t1
		ret = max(ret, c0 + solve(i+1, c0, sofar + 1));
	}
	debug(i,c0, ret);
	return ret;
}
void fff()
{
	cin >> n >> k;
	cin >> s >> t;
	if(t[0] == t[1])
	{
		ll co = 0;
		trace(s, x)
		{
			if(x == t[0])co++;
			else if(k > 0)
			{
				k--;
				co++;
			}
		}
		cout << (co*(co-1))/2 << ln;
		return;
	}
	init(dp, -1);
	cout << solve(0, 0, 0) << ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// int t;cin >> t;while(t--)
	fff();
	return 0;
}