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
const int L=2e2+7;
int a[L], co[L], ans[L], ptr[L], f[L];
std::vector<int> adj[L];
void fff()
{
	int n;
	cin >> n;
	FOR(i,0,2*n)
	{
		cin >> a[i];
		co[a[i]]++;
		adj[a[i]].pb(i);
	}
	int i, f1 = 0, f2 = 0, c1 = 0, c2 = 0;
	FOR(i,10,100)
	{
		if(co[i]>1)
		{
			ans[adj[i][ptr[i]++]] = 1;
			ans[adj[i][ptr[i]++]] = 2;
			co[i] -= 2;
			f1 = 1;
			f2 = 1;
			c1++;
			c2++;
			f[i] = 1;
		}
	}
	std::vector<int> v;
	FOR(i,10,100)
		if(co[i] && f[i] == 0)
			v.pb(i);
	c2 = 0;
	trace(v,x)
	{
		if(c2<sz(v)/2 && c1<n)ans[adj[x][ptr[x]]++] = 1, c1++, c2++;
		else ans[adj[x][ptr[x]]++] = 2;
		co[x]--;
	}
	FOR(i,10,100)
	{
		while(co[i] > 0)
		{
			if(c1 < n)ans[adj[i][ptr[i]++]] = 1, c1++;
			else ans[adj[i][ptr[i]++]] = 2;
			co[i]--;
		}
	}
	set<int>s1,s2;
	FOR(i,0,2*n)
	{
		if(ans[i] == 1)s1.insert(a[i]);
		else s2.insert(a[i]);
	}
	cout<<sz(s1)*sz(s2)<<ln;
	FOR(i,0,2*n)cout<<ans[i]<<" ";
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