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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const ll L=1e6+7;
ll ans = 0, dp[L], mat[L];
int co[L], m = 1e9 + 7, a[L], copre[L];
void pre(ll n)
{
	int tmp = sqrt(n) + 1;
	FOR(i,1,tmp)
	{
		if(n%i)continue;
		co[i]++;
		if(n != i*i)co[n/i]++;
	}
}
void process(int n)
{	
	int tmp = sqrt(n) + 1;
	FOR(i,1,tmp)
	{
		if(n%i)continue;
		co[i]--;
		if(n != i*i)co[n/i]--;
	}
	std::vector<int> v;
	FOR(i,1,tmp)
	{
		if(n%i)continue;
		ans = (ans + (dp[i-1]*co[i+1])%m)%m;
		mat[i] = dp[i-1];
		v.pb(i);
		if(n != i*i)
		{
			ans = (ans + (dp[n/i - 1] * co[n/i + 1])%m)%m;
			mat[n/i] = dp[n/i - 1];
			v.pb(n/i);
		}
	}
	trace(v, x)
	{
		dp[x] = (dp[x] + mat[x])%m;
		mat[x] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	FOR(i,0,n)
	{
		cin >> a[i];
		pre(a[i]);
	}
	dp[0] = 1;
	FOR(i,0,n)
	{
		process(a[i]);
	}
	cout<<(ans+n)%m;
	return 0;
}