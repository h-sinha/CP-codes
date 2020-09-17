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
const int L=5e3+7;
ll d[L],a[L][L], p[L], c[L];
ll get(ll x, ll r, ll n)
{
	ll mx = LLONG_MIN;
	FOR(i,1,r+1)
	{
		mx = max(mx, a[x][i]);
	}
	return mx;
}
void fff()
{
	ll n, k;
	cin >> n >> k;
	FOR(i,1,n+1)
	{
		cin >> p[i];
	}
	ll x, cur = 0;
	ll ans = LLONG_MIN, tmp, co = 0;
	FOR(i,1,n+1)cin >> c[i];
	FOR(i,1,n+1)
	{
		x = p[i], co = 1,cur = 0;
		while(x!=i)
		{
			cur += c[x];
			if(k>=co)
			ans = max(ans, cur);
			a[i][co] = cur;
			co++;
			x = p[x];
		}
		co--;
		if(k>co)
		{
			cur += c[i];
			co++;
			a[i][co] = cur;
			ans = max(ans, cur);
		}
		if(k>co)
		{
			tmp = (k%co);
			// FOR(i,1,tmp+1)
			if(tmp)
			ans = max(ans, cur*(k/(co)) + get(i,tmp, co));
			else 
			{
				ans = max(ans, cur*(k/(co)));
				ans = max(ans, cur*((k/co)-1) + get(i,co,co));
			}
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