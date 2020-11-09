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
const int L=1e3+7;
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
ll n, x, pos, m = 1e9 + 7, f[L];
ll solve(ll l, ll r, ll sm, ll lr)
{
	if(sm<0||lr<0)return 0;
	if(r<=l)
	{
		if(l > 0 && l-1 == pos)return f[lr+sm];
		return 0;
	}
	ll mid = (l+r)/2;
	if(pos>mid)
	{
		return (sm*solve(mid+1, r, sm-1, lr))%m;
	}
	else if(pos == mid)
	{
		return (solve(mid+1, r, sm, lr))%m;
	}
	else
	{
		return (lr*solve(l, mid, sm, lr-1))%m;
	}
}
void fff()
{
	cin >> n >> x >> pos;
	ll l = (x-1), r = n-x;
	cout << solve(0, n, l, r);
}
int main()
{
	f[0]=1;
	FOR(i,1,1001)
	{
		f[i] = (f[i-1]*i)%m;
	}
	#ifdef LOCAL_EXEC
	  freopen("in.txt", "r", stdin);
	  freopen("out.txt", "w", stdout);
	#else
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	#endif
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}