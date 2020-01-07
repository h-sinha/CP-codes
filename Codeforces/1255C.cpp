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

const int L=1e6+7;
int co[L], done[L];
set<int> adj[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, c;
	cin >> n;
	FOR(i,0,n-2)
	{
		cin >> a >> b >> c;
		adj[a].insert(b);
		adj[a].insert(c);
		adj[b].insert(a);
		adj[b].insert(c);
		adj[c].insert(a);
		adj[c].insert(b);
		co[a]++;
		co[b]++;
		co[c]++;
	}
	std::vector<int> o,t;
	FOR(i,1,n+1)
	{
		if(sz(adj[i]) == 2)o.pb(i);
		if(sz(adj[i]) == 3)t.pb(i);
	}
	set<pii>SET;
	pii tmp;
	FOR(i,1,n+1)SET.insert({co[i], i});
	int f1 =0, f2 = 0;
	if(sz(o) > 1)
	{
		f1 = 1;
		SET.erase({co[o[1]], o[1]});
	}
	if(sz(t) > 1)
	{
		f2 = 1;
		trace(adj[o[1]],x)
		{
			if(sz(adj[x]) == 3)
			{
				if(x != t[1])swap(t[1], t[0]);
				SET.erase({co[x],x});
				break;
			}
		}
	}
	std::vector<int> v;
	while(!SET.empty())
	{
		tmp = *SET.begin();
		SET.erase(SET.begin());
		v.pb(tmp.S);
		done[tmp.S] = 1;
		trace(adj[tmp.S], x)
		{
			if(SET.find({co[x],x}) == SET.end())continue;
			SET.erase({co[x], x});
			co[x]--;
			if(!done[x])SET.insert({co[x], x});
		}
	}	
	if(f2)v.pb(t[1]);
	if(f1)v.pb(o[1]);
	trace(v, x)cout<<x<<" ";
	return 0;
}