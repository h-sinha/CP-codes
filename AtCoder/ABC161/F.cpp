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
const int L=1e7+7;
ll dp[L], cur;
bool solve(ll n)
{
	if(n == 1)return 1;
	if(n < cur)return 0;
	if(n%cur == 0)return solve(n/cur);
	else return solve(n%cur);
 
}
void fff()
{
	ll n;
	cin >> n;
	set<ll> v;
	ll tmp = sqrt(n) + 1;
	FOR(i,1,tmp)
	{
		if(n%i == 0)
		{
			v.insert(i);
			if(n != i*i)v.insert(n/i);
		}
	}	
	tmp = sqrt(n-1) + 1;
	FOR(i,1,tmp)
	{
		if((n-1)%i == 0)
		{
			v.insert(i);
			if(n != i*i)v.insert((n-1)/i);
		}
	}	
	v.erase(1);
	init(dp,-1);
	ll ans = 0;
	trace(v,x)
	{
		cur = x;
		ans += solve(n);
	}
	cout<<ans<<ln;
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