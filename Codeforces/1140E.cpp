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
ll m = 998244353, n, k, a[L];
ll fastexpo(ll x,ll y)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll solve(std::vector<ll> v)
{
	std::vector<int> idx;
	FOR(i,0,sz(v))
		if(v[i] != -1)
			idx.pb(i);
	if(sz(idx) == 0)
		return (k * fastexpo(k-1, sz(idx) - 1)%m)%m;
	ll ans = fastexpo(k-1, idx[0] + sz(idx) - idx[sz(idx) - 1] - 1)%m;
	ll same = 0, diff = 0, tsame, tdiff;
	int l, r;
	FOR(i,0,sz(idx) - 1)
	{
		l = idx[i], r = idx[i+1];
		if(v[l] == v[r])same = 1;
		else diff = 1;
		FOR(i,l + 1, r + 1)
		{
			tsame = diff;
			tdiff = ((same * (k-1)) % m + (diff * (k-2)) % m) % m;
			same = tsame;
			diff = tdiff;
		}		
		ans = (ans * same)%m;
	}
	return ans;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> k;
	 	FOR(i,0,n)cin >> a[i];
	 	std::vector<ll> odd, even;
	 	FOR(i,0,n)
	 	{
	 		if(i & 1)
	 			odd.pb(a[i]);
	 		else
	 			even.pb(a[i]);
	 	}
	 	cout << (solve(odd) * solve(even)) %m;
		return 0;
}