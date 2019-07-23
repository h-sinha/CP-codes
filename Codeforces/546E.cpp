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
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=2e2+7;
int a[L], b[L], dp[L][L], deg[L];
std::vector<int> v[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, aa, bb;
	cin >> n >> m;
	FOR(i,1,n+1)
	{
		cin >> a[i];
		dp[i][i] = a[i];
	}
	FOR(i,1,n+1)cin >> b[i];
	FOR(i,0,m)
	{
		cin >> aa >> bb;
		v[bb].pb(aa);
		v[aa].pb(bb);
		deg[aa]++;
		deg[bb]++;
	}
	priority_queue<pair<int, int> > q;
	FOR(i,1,n+1)
			q.push({a[i]-b[i],i});
	pii cur;
	int add;
	// debug(sz(q));
	while(!q.empty())
	{
		cur = q.top();
		q.pop();
		if(cur.F != a[cur.S] - b[cur.S])continue;
		debug(cur.F, cur.S);
		trace(v[cur.S], x)
		{
			if(b[x] <= a[x])continue;
			add = min(cur.F, b[x] - a[x]);
			cur.F -= add;
			dp[cur.S][x] += add;
			a[cur.S] -= add;
			a[x] += add;
			dp[cur.S][cur.S] -= add;
			q.push({a[x]-b[x], x});
			debug(x,a[x],b[x]);
		}
	}
	FOR(i,1,n+1)
	{
		FOR(j,1,n+1)cout<<dp[i][j]<<" ";
		cout<<ln;
	}
	return 0;
}