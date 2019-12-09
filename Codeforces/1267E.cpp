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

const int L=1e2+7;
int a[L][L], vote[L];
int n, m;
void solve(int x, int f)
{
	std::vector<int> ans;
	std::vector<pii> v;
	int diff = 0;
	FOR(i,0,m)
	{
		v.pb({a[i][x] - a[i][n-1],i});
		diff += (a[i][x] - a[i][n-1]);
	}
	sort(all(v));
	int cur = 0;
	while(diff < 0)
	{
		ans.pb(v[cur].S);
		diff -= v[cur].F;
		cur++;
	}
	cout<<sz(ans)<<ln;
	trace(ans, x)cout<<x+1<<" ";
	cout<<ln;	
}
int solve(int x)
{
	std::vector<int> ans;
	std::vector<pii> v;
	int diff = 0;
	FOR(i,0,m)
	{
		v.pb({a[i][x] - a[i][n-1],i});
		diff += (a[i][x] - a[i][n-1]);
	}
	sort(all(v));
	int cur = 0;
	while(diff < 0)
	{
		ans.pb(v[cur].S);
		diff -= v[cur].F;
		cur++;
	}
	return sz(ans);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	std::vector<pii> v;
	FOR(i,0,m)
	{
		FOR(j,0,n)
			cin >> a[i][j];
	}
	int idx = -1, ret, ans = INT_MAX;
	FOR(i,0,n-1)
	{
		ret = solve(i);
		if(ret < ans)
		{
			ans = ret;
			idx = i;
		}
	}
	solve(idx, 1);
	return 0;
}