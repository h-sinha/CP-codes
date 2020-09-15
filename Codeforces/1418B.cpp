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
ll d[L], a[L], f[L], b[L], c[L], n;
int get()
{
	int ans = -1;
	d[0] = b[0];
	if(d[0]<0)ans = 0;
	FOR(i,1,n)
	{
		d[i] = b[i] + d[i-1];
		if(d[i]<0)ans = i;
	}
	return ans;
}
int get1()
{
	int ans = -1;
	d[0] = c[0];
	if(d[0]<0)ans = 0;
	FOR(i,1,n)
	{
		d[i] = c[i] + d[i-1];
	if(d[i]<0)ans = i;
	}
	return ans;
}
void fff()
{
	cin >> n;
	std::vector<ll> v;
	FOR(i,0,n)cin >> a[i];
	FOR(i,0,n)
	{
		cin >> f[i];
		if(!f[i])v.pb(a[i]);
	}
	sort(rall(v));
	int idx = 0;
	FOR(i,0,n)
	{
		b[i] = a[i];
		if(!f[i])b[i] = v[idx++];
	}
	sort(all(v));
	idx = 0;
	FOR(i,0,n)
	{
		c[i] = a[i];
		if(!f[i])c[i] = v[idx++];
	}
	int x1 = get();
	int x2 = get1();
	if(x1<x2)
	{
		FOR(i,0,n)cout << b[i]<<" ";
	}
	else
	FOR(i,0,n)cout << c[i]<<" ";
	cout << ln;
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