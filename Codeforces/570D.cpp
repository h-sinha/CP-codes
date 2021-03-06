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
const int L=5e5+7;
int t, st[L], en[L];
string s;
std::vector<int> dpt_time[L], v[L], cumsum[L];
void dfs(int vertex = 1, int depth = 1)
{
	st[vertex] = t++;
	dpt_time[depth].pb(t-1);
	if(sz(dpt_time[depth]) != 1)
	{
		cumsum[depth].pb(*cumsum[depth].rbegin());
		cumsum[depth][sz(cumsum[depth])-1] ^= (1<<(s[vertex-1]-'a'));
	}
	else
	{
		cumsum[depth].pb(1<<(s[vertex-1]-'a'));
	}
	trace(v[vertex], x)
		dfs(x, depth+1);
	en[vertex] = t-1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, node, height, l, r, co, cur;
	cin >> n >> m;
	FOR(i,2,n+1)
	{
		cin >> a;
		v[a].pb(i);
	}
	cin >> s;
	dfs();
	while(m--)
	{
		cin >> node >> height;
		r = upper_bound(all(dpt_time[height]), en[node]) - dpt_time[height].begin();
		l = lower_bound(all(dpt_time[height]), st[node]) - dpt_time[height].begin();
		if(l>r || l == r)cout<<"Yes\n";
		else
		{
			if(l > 0)
				cur = cumsum[height][r-1] ^ cumsum[height][l-1];
			else
				cur = cumsum[height][r-1];	
			co = __builtin_popcount(cur);
			if(co>1)cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}