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
ll a[5], b[5], c[5];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll q, aa, bb, cc, ans;
	cin >> q;
	while(q--)
	{
		cin >> a[0] >> b[0] >> c[0];
		ll ans = LLONG_MAX;
		a[1] = a[0] + 1;
		a[2] = a[0] - 1;
		b[1] = b[0] + 1;
		b[2] = b[0] - 1;
		c[1] = c[0] + 1;
		c[2] = c[0] - 1;
		FOR(i,0,3)
			FOR(j,0,3)
				FOR(k,0,3)
					ans = min(ans, abs(a[i]-b[j]) + abs(b[j] - c[k]) + abs(a[i]-c[k]));
		cout<<ans<<ln;
	}
	return 0;
}