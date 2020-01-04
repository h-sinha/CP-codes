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
ll dist[L];
set<ll>SET;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	ll x;
	cin >> n >> m;
	revpr q;
	FOR(i,0,n)
	{
		cin >> x;
		q.push({1,x});
		SET.insert(x);
	}
	int cur = 0, f1 , f2;
	ll ans = 0;
	pii tmp;
	while(cur < m)
	{
		f1 = f2 = 0;
		tmp = q.top();
		q.pop();
		if(SET.find(tmp.S + tmp.F) == SET.end())f1 = 1;
		if(SET.find(tmp.S - tmp.F) == SET.end())f2 = 1;
		if(f1)
		{
			dist[cur++] = tmp.S + tmp.F;
			ans += tmp.F;
			q.push({tmp.F + 1, tmp.S});
			SET.insert(dist[cur-1]);
			f1 = 0;
		}
		else if(f2)
		{
			dist[cur++] = tmp.S - tmp.F;
			ans += tmp.F;
			SET.insert(dist[cur-1]);
			q.push({tmp.F + 1, tmp.S});
			f2 = 0;
		}
		if(f1 + f2)q.push(tmp);
	}
	cout<<ans<<ln;
	FOR(i,0,m)cout<<dist[i]<<" ";
	return 0;
}