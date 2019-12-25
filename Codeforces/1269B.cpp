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
ll a[L], b[L], c[L];
ll n, m;
ll check(int x)
{
	ll inc = 0;
	if(a[x] <= b[0])inc = b[0]-a[x];
	else inc = b[0] - a[x] + m;
	FOR(i,0,n)c[i] = (a[i] + inc)%m;
	sort(c,c+n);
	FOR(i,0,n)
	{
		if(c[i] != b[i])return INT_MAX;
	}
	return inc;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	FOR(i,0,n)
	{
		cin >> a[i];
	} 
	sort(a,a+n);
	FOR(i,0,n)cin >> b[i];
	sort(b,b+n);
	ll ans = INT_MAX;
	FOR(i,0,n)
	{
		ans = min(ans,check(i));
	}
	cout<<ans;
	return 0;
}