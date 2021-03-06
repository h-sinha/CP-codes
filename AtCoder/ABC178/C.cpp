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
map<ll,ll> counter;
ll m = 1e9 + 7;
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
ll p2[L], p8[L], fact[L];
ll get(ll n, ll x)
{
	if(x>n)return 0;
	ll num = fact[n];
	ll den = fact[x];
	den *= fact[n-x];
	den %= m;
	return (num * fastexpo(den, m-2))%m;
}
void fff()
{
	ll n;
	cin >> n;
	if(n<2)
	{
		cout << 0 << ln;
		return;
	}
	p2[0] = p8[0] = 1;
	fact[0] = 1;
	FOR(i,1,n+1)
	{
		fact[i] = (fact[i-1]*i)%m;
		p2[i] = (p2[i-1]*2LL)%m;
		p8[i] = (p8[i-1]*8LL)%m;
	}
	ll ans = 0, tmp;
	FOR(i,2,n+1)
	{
		tmp = ((p2[i]-2)%m * p8[n-i])%m;
		tmp = (tmp * get(n,i));
		tmp %= m;
		ans = (ans + tmp)%m;
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