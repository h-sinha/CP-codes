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
map<ll,ll> counter;
int l[L], r[L], n, m, ans, a[302] ;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> m;
	 	FOR(i,1,n+1)cin >> a[i];
	 	FOR(i,0,m)cin >> l[i] >> r[i];
	 	int idx = 0;
	 	FOR(i,1,n+1)
	 	{
	 		FOR(j,0,m)
	 		{
	 			if(l[j] <= i && r[j] >= i)
	 			{
	 				FOR(k,l[j], r[j]+1)a[k]--;
	 			}
	 		}
	 		int mx = INT_MIN, mn = INT_MAX;
	 		FOR(j,1,n+1)
	 		{
	 			mx = max(mx, a[j]);
	 			mn = min(mn, a[j]);
	 		}
	 		if(ans < mx - mn)
	 		{
	 			idx = i;
	 			ans = mx - mn;
	 		}
	 		FOR(j,0,m)
	 		{
	 			if(l[j] <= i && r[j] >= i)
	 			{
	 				FOR(k,l[j], r[j]+1)a[k]++;
	 			}
	 		}
	 	}
	 	cout<<ans<<ln;
	 	std::vector<int> v;
	 	FOR(i,0,m)
	 	{
	 		if(l[i] <= idx && r[i] >= idx)
	 		{
	 			v.pb(i+1);
	 		}
	 	}
	 	cout<<sz(v)<<ln;
	 	trace(v,x)cout<<x<<" ";
	 	cout<<ln;
		return 0;
}