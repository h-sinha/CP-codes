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
int type[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll q, n, t, a, b, tt;
	cin >> q;
	while(q--)
	{
		cin >> n >> t >> a >> b;
		std::vector<pii> v;
		ll te =0, td = 0;
		FOR(i,0,n)
		{
			cin >> type[i];
			if(type[i])td++;
			else te++;
		}
		FOR(i,0,n)
		{
			cin >> tt;
			v.pb({tt, i});
		}
		v.pb({t+1,0});
		sort(all(v));
		pii x;
		ll co = 0, diff,e = 0, d = 0, ans = 0, cur, curans;
		FOR(i,0,n+1)
		{
			x = v[i];
			cur = e*a + d*b;
			if(cur <= x.F - 1)
			{
				diff = min(x.F - 1 - cur, t - cur);
				cur = min(te, diff/a);
				diff -= cur*a;
				cur += min(td, diff/b);
				cur += i;
				ans = max(ans, cur);
			}
			int l = i;
			while(l < n+1 && v[l].F == v[i].F)
			{
				if(type[v[l].S])d++, td--;
				else e++, te--;
				l++;
			}
			i = l-1;
		}
		cout<<ans<<ln;
	}	
	return 0;
}