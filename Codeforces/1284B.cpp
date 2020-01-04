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

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e6+7;
map<ll,ll> counter;
ll mxel[L], mnel[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, x, y, it, mx, mn;
	cin >> n;
	ll ans = 0;
	pbds SET;
	ll co = 0;
	FOR(i,0,n)
	{
		cin >> x;
		mn = INT_MAX;
		mx = INT_MIN;
		int f = 0;
		set<ll>ss;
		FOR(j,0,x)
		{
			cin >> y;
			ss.insert(y);
			if(y > mn && j != 0)f = 1;
			mn = min(mn, y);
			mx = max(mx, y);
		}
		if(f)
		{
			ans += 2LL*n-1LL;
			ans-= (2LL*co);
			co++;
			mxel[i] = -1;
			continue;
		}
		if(sz(ss) > 1)ans++;
		SET.insert({mn,i});
		mxel[i] = mx;
		mnel[i] = mn;
	}
	FOR(i,0,n)
	{
		if(mxel[i] == -1)continue;
		SET.erase({mnel[i],i});
		it = SET.order_of_key({mxel[i],INT_MIN});
		SET.insert({mnel[i],i});
		ans += it;
	}
	cout<<ans;
	return 0;
}