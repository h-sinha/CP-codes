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
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L = 3e5+7;
const int M=20;
int n, m, k;
ll a[M], po[M], dp[M][L];
std::map<pii, ll> counter;
ll solve(int idx, int sofar)
{
	ll x = __builtin_popcount(sofar);
	if(x == m)return 0;
	if(x == n || x > m)return INT_MIN;
	if(dp[idx][sofar] != 0)return dp[idx][sofar];
	x = 0;
	ll ret = 0;
	FOR(i,1,n+1)
	{
		if((sofar & po[i-1]) == 0)
		{
			if(counter.find({idx, i}) != counter.end())x = counter[{idx,i}];
			else x = 0;
			ret = max(ret, x + a[i] + solve(i, (sofar|po[i-1])));
		}
	}
	return  dp[idx][sofar] = ret;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> m >> k;
	 	ll x,y,c;
	 	FOR(i,1,n+1)
	 		cin >> a[i];
	 	FOR(i,0,k)
	 	{
	 		cin >> x >> y >> c;
	 		counter[{x,y}] = max(counter[{x,y}], c);
	 	}
	 	po[0] = 1;
	 	FOR(i,1,19)po[i] = (po[i-1]*2LL);
	 	ll ans = 0;
		FOR(i,1,n+1)ans = max(ans, a[i] + solve(i,po[i-1]));
		cout<<ans;
		return 0;

}