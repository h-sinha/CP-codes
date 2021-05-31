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
const int L=1e3+7;
ll n;
string ss;
ll r[L], p[L], s[L];
std::vector<pii> v;
ll get(ll x, ll y)
{
	ll ret = 0;
	if(x>=0)
	{
		ret += r[x];
	}
	if(x<=y && y >= 0)
	{
		ret += p[y];
		if(x >= 0)ret -= p[x];
	}
	if(n-1>=y+1)
	{
		ret += s[n-1];
		if(y >= 0)ret -= s[y];
	}
	// debug(x,y,ret);
	// v.pb({x,y});
	return ret;
}
void fff()
{
	cin >> n;
	cin >> ss;
	FOR(i,0,n+2)r[i] = 0, s[i] = 0, p[i] = 0;
	FOR(i,0,n)
	{
		if(ss[i] == 'R')p[i]++, s[i]--;
		if(ss[i] == 'P')s[i]++, r[i]--;
		if(ss[i] == 'S')r[i]++, p[i]--;
		if(i)p[i] += p[i-1], r[i] += r[i-1], s[i] += s[i-1];
	}
	ll ans = 0;
	FOR(i,0,n)
	{
		FOR(j,i,n)
		{
			if(get(i,j) > 0)ans++;
			// debug(i,j,ans);
		}
	}
	FOR(i,0,n)
	{
		if(get(-1, i) > 0)ans++;
			// debug(-1,i,ans);
	}
	if(s[n-1] > 0)ans++;
	// sort(all(v));
	// trace(v,x)
	// {
	// 	cerr << 0<<".."<<x.F <<" "<<x.F+1<<".."<<x.S<<" "<<x.S+1<<".."<<n-1<<endl;
	// }
	cout << ans << ln;
}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}