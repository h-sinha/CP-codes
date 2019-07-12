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
int x[L], y[L], deg[L], ans[L], done[L];
set<int> v[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	FOR(i,0,m)
	{
		cin >> x[i] >> y[i];
		v[x[i]].insert(y[i]);
		v[y[i]].insert(x[i]);
		deg[x[i]]++;
		deg[y[i]]++;
	}
	FOR(i,1,n+1)
	{
		if(deg[i] < k)
		{
			done[i] = 1;
			deg[i] = 0;
			trace(v[i], x)
			{
				v[x].erase(i);
				deg[x]--;
			}
		}
	}
	set<int>SET;
	FOR(i,1,n+1)
		if(deg[i] >= k)
			SET.insert(i);
	ans[m-1] = sz(SET);
	RFOR(i,m-1,0)
	{
		while(!SET.empty() && deg[*SET.begin()]<k)SET.erase(SET.begin());
		if(SET.empty())break;
		if(v[x[i]].find(y[i]) != v[x[i]].end())
		deg[x[i]]--, deg[y[i]]--;
		if(deg[x[i]] == k-1)
		{
			SET.erase(x[i]);
			trace(v[x[i]], xx)
			{
				if(xx == y[i])continue;
				deg[xx]--;
				v[xx].erase(x[i]);
				if(deg[xx] == k-1)SET.erase(xx), done[xx] = 1;
			}
			v[x[i]].clear();
		}
		if(deg[y[i]] == k-1)
		{
			SET.erase(y[i]);
			done[y[i]] = 1;
			trace(v[y[i]], xx)
			{
				if(xx == x[i])continue;
				deg[xx]--;
				v[xx].erase(y[i]);
				if(deg[xx] == k-1)SET.erase(xx), done[xx] = 1;
			}
			v[y[i]].clear();
		}
		v[x[i]].erase(y[i]);
		v[y[i]].erase(x[i]);
		ans[i-1] = sz(SET);
	}
	FOR(i,0,m)cout<<ans[i]<<ln;
	return 0;
}