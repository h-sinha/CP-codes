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
std::vector<ll> v1, v2, v3;
void fff()
{
	int n, k, t, a, b;
	cin >> n >> k;
	FOR(i,0,n)
	{
		cin >> t >> a >> b;
		if(a&b)v1.pb(t);
		else if(a)v2.pb(t);
		else if(b)v3.pb(t);
	}
	sort(all(v1));
	sort(all(v2));
	sort(all(v3));
	FOR(i,1,sz(v1))v1[i] += v1[i-1];
	FOR(i,1,sz(v2))v2[i] += v2[i-1];
	FOR(i,1,sz(v3))v3[i] += v3[i-1];
	ll ans = LLONG_MAX, req;
	if(k<=sz(v2) && k<=sz(v3))
	{
		ans = v2[k-1] + v3[k-1];
	}
	FOR(i,0,sz(v1))
	{
		req = k - i - 1;
		if(req>sz(v2)||req>sz(v3))continue;
		if(req == 0)ans = min(ans, v1[i]);
		else ans = min(ans, v1[i] + v2[req-1] + v3[req-1]);
	}
	cout << ((ans == LLONG_MAX) ? -1 : ans)<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}