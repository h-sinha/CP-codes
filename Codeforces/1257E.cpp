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
int dp1[L],dp2[L],dp3[L], mn[L];
int lis(std::vector<int> a)
{
	int n = a.size();
	int cur=0;
	std::vector<int> v;
	v.pb(a[0]);
	std::vector<int> ::iterator it;
	FOR(i,1,n)
	{
		if(a[i]<v[0])v[0]=a[i];
		else if(a[i]>v[sz(v)-1])v.pb(a[i]);
		else
		{
			it=lower_bound(all(v),a[i]);
			v[it-v.begin()]=a[i];
		}
	}
	return sz(v);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k1, k2, k3, a, n;
	cin >> k1 >> k2 >> k3;
	std::vector<int> v1, v2, v3;
	n = k1+k2+k3;
	FOR(i,0,k1)
	{
		cin >> a;
		v1.pb(a);
	}
	FOR(i,0,k2)
	{
		cin >> a;
		v2.pb(a);
	}
	FOR(i,0,k3)
	{
		cin >> a;
		v3.pb(a);
	}
	sort(all(v1));
	sort(all(v2));
	sort(all(v3));
	std::vector<int> v;
	trace(v1, x)v.pb(x);
	trace(v2, x)v.pb(x);
	trace(v3, x)v.pb(x);
	cout<<n-lis(v);
	return 0;
}