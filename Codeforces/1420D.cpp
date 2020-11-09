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
map<int,int> co, h, rr;
ll m = 998244353;
ll fastexpo(ll x,ll y,ll m=998244353)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll fact[L];
ll get(ll n, ll r)
{
	if(n<r||r<0)return 0;
	ll num = fact[n];
	ll den = (fact[r] * fact[n-r])%m;
	return (num * fastexpo(den, m-2))%m;
}
void fff()
{
	int n, k, l, r;
	cin >> n >> k;
	fact[0] = 1;
	FOR(i,1,n+1)fact[i] = (fact[i-1] * i)%m;
	FOR(i,0,n)
	{
		cin >> l >> r;
		co[l]++, co[r]++;
		h[l]++;
		rr[r]++;
	}
	ll ans = 0, prv = 0, pp = 0;
	trace(co, x)
	{
		if(h.find(x.F)!=h.end())pp += h[x.F];
		ans -= get(prv, k);
		ans += m;
		ans %= m;			
		ans += get(pp, k);
		ans %= m;
		if(rr.find(x.F)!=rr.end())pp -= rr[x.F];
		prv = pp;
	}
	cout << ans << ln;
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