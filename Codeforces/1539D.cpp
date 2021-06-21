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
std::vector<pii> v;
void fff()
{
	int n;
	cin >> n;
	ll a, b, s = 0;
	FOR(i,0,n)
	{
		cin >> a >> b;
		v.pb({b, a});
		s += a;
	}
	sort(all(v));
	ll cur = 0;
	ll ans = 2*s,tot = 0;
	int l = 0, r = n-1;
	ll d;
	// trace(v,x)debug(x.F, x.S);
	while(l<r)
	{
		// debug(cur, v[l].F);
		if(v[l].F <= cur)
		{
			cur += v[l].S;
			tot += v[l].S;
			l++;
		}
		else if(v[l].F >= cur + v[r].S)
		{
			cur += v[r].S;
			tot += 2LL*v[r].S;
			r--;
		}
		else
		{
			d = min(v[r].S, v[l].F-cur);
			v[r].S -= d;
			cur += d;
			cur += v[l].S;

			tot += v[l].S;
			tot += 2LL*d;
			l++;
		}
		// debug(l,r,cur,tot,d);
	}
	// debug(v[l].F, v[l].S);
	if(cur >= v[l].F)
	{
		tot += v[l].S;
	}
	else if(v[l].F < v[l].S+cur)
	{
		d = v[l].F-cur;
		v[l].S -= d;
		tot += 2LL*d;
		tot += v[l].S;
	}
	else tot += v[l].S * 2LL;
	cout << min(ans, tot) << ln;
}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	// int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}