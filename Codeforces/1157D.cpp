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
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const ll L=1e6+7;
ll a[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> k >> n;
	FOR(i,0,n)
	{
		a[i] = i + 1;
		k -= (i+1);
	}
	if(k < 0)
	{
		cout<<"NO";
		return 0;
	}
	ll tot = (k/n);
	k -= (tot*n);
	FOR(i,0,n)a[i] += tot;
	ll cur, f = 1;
	while(k>0 && f)
	{
		f = 0;
		RFOR(i,n-1,1)
		{
			if(k == 0)break;
			cur = min(2*a[i-1]-a[i], k);
			k -= cur;
			a[i] += cur;
			if(cur > 0)f = 1;
		}
	}
	if(k>0)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	FOR(i,0,n)cout<<a[i]<<" ";
	return 0;
}