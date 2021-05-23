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
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int xx = 0;
void fff()
{
	xx++;
	ll w, n;
	cin >> w >> n;
	std::vector<ll> v(w), dp(w);
	FOR(i,0,w)
	{
		cin >> v[i];
	}
	sort(all(v));
	FOR(i,0,w)dp[i] = v[i];
	FOR(i,1,w)dp[i] += dp[i-1];
	std::vector<ll> ::iterator it;
	ll ans = LLONG_MAX, cur = 0, x, aux;
	FOR(i,0,w)
	{
		it = upper_bound(all(v), v[i] + n/2);
		if(it == v.end())
		{
			cur = dp[w-1] - dp[i];
			cur -= (v[i]*(w-i-1));
			if(i)
			{
				cur += (v[i]*i - dp[i-1]);
			}
			ans = min(ans, cur);
		}
		else
		{
			x = it-v.begin();
			cur = dp[x-1] - dp[i];
			cur -= (v[i]*(x-1-i));
			if(i)
			{
				cur += (v[i]*i - dp[i-1]);
			}
			aux = 0;
			if(x)aux = dp[w-1] - dp[x-1];
			else aux = dp[w-1];
			aux = -aux;
			aux += (n*(w-x));
			aux += (v[i]*(w-x));
			cur += aux;
			ans = min(ans, cur);
		}
	}
	RFOR(i,w-1,0)
	{
		it = lower_bound(all(v), v[i] - n/2);
		if(it == v.begin())continue;
		else
		{
			x = it-v.begin();
			cur = dp[w-1] - dp[i];
			cur -= (v[i]*(w-1-i));

			cur -= (dp[i-1] - dp[x-1]);
			cur += (v[i]*(i-x));
			aux = 0;
			aux = dp[x-1];
			aux -= (v[i] * (x));
			aux += (n*(x));
			cur += aux;
			ans = min(ans, cur);
		}
	}
	cout <<"Case #"<<xx<<": "<<ans<<ln;
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