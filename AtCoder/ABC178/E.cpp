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
ll x[L], y[L];
void fff()
{
	ll n;
	cin >> n;
	ll mx1, mx2, mx3, mx4;
	mx1 = mx2 = mx3 = mx4 = LLONG_MIN;
	FOR(i,0,n)
	{
		cin >> x[i] >> y[i];	
		mx1 = max(mx1, x[i] + y[i]);
		mx2 = max(mx2, -x[i] + y[i]);
		mx3 = max(mx3, x[i] - y[i]);
		mx4 = max(mx4, -x[i] - y[i]);
	}
	std::vector<pii> v;
	FOR(i,0,n)
	{
		if(x[i] + y[i] == mx1)
		{
			v.pb({x[i], y[i]});
			break;
		}
	}
	FOR(i,0,n)
	{
		if(-x[i] + y[i] == mx2)
		{
			v.pb({x[i], y[i]});
			break;
		}
	}
	FOR(i,0,n)
	{
		if(x[i] - y[i] == mx3)
		{
			v.pb({x[i], y[i]});
			break;
		}
	}
	FOR(i,0,n)
	{
		if(-x[i] - y[i] == mx4)
		{
			v.pb({x[i], y[i]});
			break;
		}
	}
	ll cur1, cur2, cur3, cur4,ans = LLONG_MIN;
	FOR(i,0,n)
	{
		trace(v,cur)
		{
			ans = max(ans, abs(x[i]-cur.F) + abs(y[i]-cur.S));
		}
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