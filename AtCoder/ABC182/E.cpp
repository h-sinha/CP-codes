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
const int L=1507;
std::vector<int> r[L];
std::vector<int> c[L];
std::vector<pii> v;
int dpr[L][L], dpc[L][L];
void fff()
{
	ll h,w,n,m, a, b;
	cin >> h >> w >> n >> m;
	// bulb
	FOR(i,0,n)
	{
		cin >> a >> b;
		v.pb({a,b});
	}
	// blocks
	FOR(i,0,m)
	{
		cin >> a >> b;
		r[a].pb(b);
		c[b].pb(a);
	}
	FOR(i,0,h+1)sort(all(r[i]));
	FOR(i,0,w+1)sort(all(c[i]));
	std::vector<int> ::iterator it;

	int xx;
	trace(v, x)
	{
		it = upper_bound(all(r[x.F]), x.S) ;
		// right
		if(it != r[x.F].end())
		{
			xx = it-r[x.F].begin();
			dpr[x.F][r[x.F][xx]]--;
			dpr[x.F][x.S]++;
		}
		else
		{
			dpr[x.F][x.S]++;
			dpr[x.F][w+1]--;
		}
		// left
		it = lower_bound(all(r[x.F]), x.S);
		if(it != r[x.F].begin())
		{
			it--;
			xx = it-r[x.F].begin();
			dpr[x.F][r[x.F][xx]+1]++;
			dpr[x.F][x.S+1]--;
		}
		else
		{
			dpr[x.F][1]++;
			dpr[x.F][x.S+1]--;
		}
		// down
		it = upper_bound(all(c[x.S]), x.F) ;
		if(it != c[x.S].end())
		{
			xx = it-c[x.S].begin();
			// debug(xx, sz(c[x.S]));
			dpc[c[x.S][xx]][x.S]--;
			dpc[x.F][x.S]++;
		}
		else
		{
			dpc[x.F][x.S]++;
			dpc[h+1][x.S]--;
		}
		// up
		it = lower_bound(all(c[x.S]), x.F);
		if(it != c[x.S].begin())
		{
			it--;
			xx = it-c[x.S].begin();
			dpc[c[x.S][xx]+1][x.S]++;
			dpc[x.F+1][x.S]--;
		}
		else
		{
			dpc[1][x.S]++;
			dpc[x.F+1][x.S]--;
		}
	}
	FOR(i,1,h+1)
	{
		FOR(j,1,w+1)
		{
			dpr[i][j] += dpr[i][j-1];
		}
	}
	FOR(j,1,w+1)
	{
		FOR(i,1,h+1)
		{
			dpc[i][j] += dpc[i-1][j];
		}
	}
	int ans = 0;
	FOR(i,1,h+1)
	{
		FOR(j,1,w+1)
		{
			if(dpr[i][j] || dpc[i][j])ans++;
		}
	}
	cout << ans<<ln;
}
int main()
{
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