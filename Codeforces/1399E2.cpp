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
ll w[L], s, co[L], d[L], n, w1[L];
std::vector<pii> v[L];
int dfs(int vertex, int parent)
{
	int ret = 0;
	trace(v[vertex], x)
	{
		if(x.F!=parent)
		{
			co[x.S] = dfs(x.F, vertex);
			ret += co[x.S];
		}
	}
	if(sz(v[vertex]) == 1)return 1;
	return ret;
}
std::vector<ll> solve(priority_queue <pii> q, ll sumis)
{
	if(sumis == 0)return std::vector<ll> ();
	pii tmp;
	FOR(i,0,n-1)w1[i] = w[i];
	std::vector<ll> ret;
	ret.pb(sumis);
	while(sumis > 0)
	{
		tmp = q.top();
		q.pop();
		sumis -= tmp.F;
		w1[tmp.S]/=2;
		ret.pb(sumis);
		if(w1[tmp.S])q.push({((w1[tmp.S]+1)/2)*co[tmp.S], tmp.S});
	}
	reverse(all(ret));
	return ret;
}
void fff()
{
	ll a , b,c;
	cin >> n >> s;
	priority_queue<pii>q[2];
	FOR(i,0,n+1)v[i].clear(), co[i] = 0;
	std::vector<ll> val[2];
	FOR(i,0,n-1)
	{
		cin >> a >> b >> c >> d[i];
		v[a].pb({b,i});
		v[b].pb({a,i});
		w[i] = c;
	}
	dfs(1,-1);
	ll sumis[2] = {0};
	FOR(i,0,n-1)
	{
		sumis[d[i]-1] += co[i]*w[i];
		q[d[i]-1].push({co[i]*((w[i]+1)/2),i});
	}
	val[0] = solve(q[0], sumis[0]);
	val[1] = solve(q[1], sumis[1]);
	std::vector<ll> :: iterator it;
	ll ans = INT_MAX;
	if(sz(val[0]) == 0 || sz(val[1]) == 0)
	{
		if(sz(val[0]) == 0)
		{
			it = upper_bound(all(val[1]), s);
			ans = 2*(sz(val[1])-(it-val[1].begin()));
		}
		else
		{
			it = upper_bound(all(val[0]), s);
			ans = (sz(val[0])-(it-val[0].begin()));
		}
		cout << ans<<ln;
		return;
	}
	FOR(i,0,sz(val[0]))
	{
		it = upper_bound(all(val[1]), s-val[0][i]);
		if(it == val[1].end() && s<val[0][i])continue;
		ans = min(ans,sz(val[0])-i-1+2*(sz(val[1])-(it-val[1].begin())));
		
	}
	cout << ans<<ln;
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