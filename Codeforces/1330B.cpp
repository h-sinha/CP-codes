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
int c1[L], c2[L], co[L], a[L];
void fff()
{
	int n;
	cin >> n;
	FOR(i,0,n+1)c1[i] = 0, c2[i] = 0, co[i] = 0;
	FOR(i,0,n)
	{
		cin >> a[i];
	}	
	set<int>SET;
	FOR(i,0,n)
	{
		co[a[i]]++;
		if(co[a[i]] > 1)break;
		SET.insert(a[i]);
		if(sz(SET) == i+1 && *SET.begin() == 1 && *SET.rbegin() == i+1)c1[i] = 1;
	}
	SET.clear();
	FOR(i,0,n+1)co[i] = 0;
	RFOR(i,n-1,0)
	{
		co[a[i]]++;
		if(co[a[i]] > 1)break;
		SET.insert(a[i]);
		if(sz(SET) == n-i && *SET.begin() == 1 && *SET.rbegin() == n-i)c2[i] = 1;
	}
	std::vector<int> v;
	FOR(i,0,n-1)
	{
		if(c1[i] == 1 && c2[i+1] == 1)v.pb(i);
	}
	cout<<sz(v)<<ln;
	trace(v,x)cout<<x+1<<" "<<n-x-1<<ln;
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