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
ll a[L], b[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	ll n = s.length();
	ll co = 0;
	FOR(i,0,n)
	{
		if(s[i] == 'v')co++;
		else
		{
			if(co!=0)
			a[i] = co-1;
			co = 0;
		}
	}
	co = 0;
	RFOR(i,n-1,0)
	{
		if(s[i] == 'v')co++;
		else
		{
			if(co!=0)
			b[i] = co-1;
			co = 0;
		}
	}
	ll ans = 0;
	FOR(i,1,n)a[i] += a[i-1];
	RFOR(i,n-1,0)b[i] += b[i+1];
	FOR(i,0,n)
		if(s[i] == 'o')
			ans += (a[i]*b[i]);
	cout<<ans;
	return 0;
}