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
ld  h, c, t;
ld get(ll x)
{
	if(x<=0)return INT_MAX;
	ld num = x*h + (x-1)*c;
	return abs((num / (2*x-1)) - t);
}
ld mn,ans;
void fff()
{
	cin >> h >> c >> t;
	ld mn = abs(h-t);
	ll ans = 1;
	ld a = (h+c)/2;
	if(abs(a-t) < mn)
	{
		mn = abs(a-t);
		ans = 2;
	}
	ll x = (c+h-2*t)+c-t;
	x /= (2*c+2*h-4*t);
	x -= 1;
	a = get(x);
	if(a<mn)
	{
		mn = a;
		ans = x*2-1;
	}
	a = get(x+1);
	if(a<mn)
	{
		mn = a;
		ans = (x+1)*2-1;
	}
	a = get(x-1);
	if(a<mn)
	{
		mn = a;
		ans = (x-1)*2-1;
	}
	x = (c-t);
	x/=(c+h-2*t);
	a = get(x);
	if(a<mn)
	{
		mn = a;
		ans = x*2-1;
	}
	a = get(x+1);
	if(a<mn)
	{
		mn = a;
		ans = (x+1)*2-1;
	}
	a = get(x-1);
	if(a<mn)
	{
		mn = a;
		ans = (x-1)*2-1;
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}