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
ll a[L], d[L], b[L];
ll geta(int l, int r)
{
	ll ans = a[r];
	if(l)ans -= a[l-1];
	return ans;
}
ll getd(int l, int r)
{
	ll ans = d[r];
	if(l)ans -= d[l-1];
	return ans;
}
ll get(ll n)
{
	return (n*(n+1))/2;
}
void fff()
{
	ll n, x;
	cin >> n >> x;
	FOR(i,0,n)
	{
		cin >> a[i];
		b[i] = b[i+n] = a[i];
		a[i+n] = a[i];
	}
	FOR(i,0,n)d[i] = (a[i]*(a[i]+1))/2;
	FOR(i,1,2*n)d[i] += d[i-1], a[i] += a[i-1];
	ll it, ans = 0, lft;
	FOR(i,0,2*n)
	{
		it = lower_bound(a,a+2*n,a[i]-x)-a;
		if(i == it)
		{
			ans = max(ans, get(b[i]) - get(b[i]-x));
			continue;
		}
		lft = x - geta(it,i);
		debug(i,a[i],d[i],lft,it);
		if(lft > 0 && it == 0)continue;
		if(lft == 0)ans = max(ans, getd(it,i));
		else ans = max(ans, getd(it,i) + get(b[it-1]) - get(b[it-1]-lft));
		debug(ans);
	}
	cout<<ans<<ln;
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