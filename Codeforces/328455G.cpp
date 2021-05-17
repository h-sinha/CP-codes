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
ll a[L], cur, co[30], po[30];
void add(ll x)
{
	int c = 0;
	while(x > 0)
	{
		if(x&1)
		{
			co[c]++;
			if(co[c] == 1)cur += po[c];
		}
		x >>= 1;
		c++;
	}
}
void rem(ll x)
{
	int c = 0;
	while(x > 0)
	{
		if(x&1)
		{
			co[c]--;
			if(co[c] == 0)cur -= po[c];
		}
		x >>= 1;
		c++;
	}
}
void fff()
{
	cur = 0;
	int n, v;
	cin >> n >> v;
	FOR(i,0,n)cin >> a[i];
	int l = 0, r = -1, ans = 0;
	while(1)
	{
		r++;
		if(r >= n)break;
		add(a[r]);
		while(cur > v && l < r)
		{
			rem(a[l]);
			l++;
		}
		if(cur <= v)
		{
			ans = max(ans, r-l+1);
		}
	}
	cout << ans << ln;
	FOR(i,0,22)co[i] = 0;
}
int main()
{
	po[0] = 1;
	FOR(i,1,22)po[i] = (po[i-1] * 2);
	freopen("wifi.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}