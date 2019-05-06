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
//nah OF ELEMENTS < A
//X.order_of_key(A)

const int L=2001;
map<ll,ll> counter;
std::vector<pii> v[L];
std::vector<int> par(L), visit(L);
int nah = 0, MOD = 998244353;
void clear_all()
{
	FOR(i,0,L)v[i].clear();
	fill(all(par), 0);
	fill(all(visit), 0);
	nah = 0;
}
void dfs(int vertex)
{
	visit[vertex] = 1;
	trace(v[vertex], x)
	{
		if(!visit[x.F])
		{
			par[x.F] = par[vertex] ^ x.S;
			dfs(x.F);
		}
		else if(par[x.F] != par[vertex] ^ x.S)
		{
			nah = 1;
			return;
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	cin >> s;
	 	int n = s.length(), cur, ans, final_ans = 0;
	 	reverse(all(s));
	 	FOR(q,1,n)
	 	{
	 		clear_all();
	 		FOR(i,1,n/2 + 1)
	 		{
	 			v[i].pb(mp(n - i + 1, 0));
	 			v[n - i + 1].pb(mp(i, 0));
	 		}
	 		FOR(i,1,q/2 + 1)
	 		{
	 			v[i + n].pb(mp(n + q - i + 1, 0));
	 			v[n + q - i + 1].pb(mp(i + n, 0));
	 		}
	 		FOR(i,0,n)
	 		{
	 			if(s[i] != '?')
	 			{
	 				cur = s[i] - '0';
	 				v[i + 1].pb(mp(i + n + 1, cur));
	 				v[i + n + 1].pb(mp(i + 1, cur));
	 			}
	 		}
	 		FOR(i,q + 1, n + 1)
	 		{
	 			v[0].pb(mp(i + n, 0));
	 			v[i + n].pb(mp(0, 0));
	 		}
	 		v[0].pb(mp(n + q, 1));
	 		v[n + q].pb(mp(0, 1));
	 		ans = 1;
	 		FOR(i, 0, 2*n + 1)
	 		{
	 			if(!visit[i])
	 			{
	 				dfs(i);
	 				if(i > 0)ans = (ans * 2) % MOD;
	 			}
	 		}
	 		if(nah)ans = 0;
	 		final_ans = (final_ans + ans) % MOD;
	 	}
	 	cout << final_ans;
		return 0;
}