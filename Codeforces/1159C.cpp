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

const ll L=1e6+7;
map<ll,ll> counter;
map<ll,ll> ct;
map<ll,ll> done;
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, m;
	 	cin >> n >> m;
	 	set<ll>v;
	 	ll mx =LLONG_MIN, mn = LLONG_MAX;
	 	ll ans = 0;
	 		std::vector<ll> b(m);
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
	 		ans += (a[i]*m);
	 		counter[a[i]]++;
	 		v.insert(-a[i]);
	 		ct[-a[i]]++;
	 		mx = max(mx, a[i]);
	 	}
	 	FOR(i,0,m)
	 	{
	 		cin >> b[i];
	 		mn = min(mn, b[i]);
	 	}
	 	sort(b.rbegin(), b.rend());
	 	if(mx > mn)
	 	{
	 		cout<<"-1";
	 		return 0;
	 	}
	 	ll f = 0;
	 	set<ll>::iterator it;
		FOR(i,0,m)
		{
			if(counter.find(b[i]) != counter.end())continue;
			it = v.upper_bound(-b[i]);
			while(done[*it] == (m-1) * ct[*it])
			{
				v.erase(it);
				if(sz(v) == 0)
				{
					f = 1;
					break;
				}
				it = v.upper_bound(-b[i]);
			}
			done[*it]++;
			if(it == v.end() || f)
			{
				cout<<"-1";
				return 0;
			}
			ans += (abs( b[i] + *it));
		}
		cout<<ans;
		return 0;
}