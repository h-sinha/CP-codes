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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
std::vector<ll> f;
set<ll> ans;
void solve(ll n)
{
	ll tmp = sqrt(n), i ;
	for ( i = 1; i <=tmp ; ++i)
	{
		if(n%i)continue;
		f.pb(i);
		f.pb(n/i);
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, tmp, tr;
	 	cin >> n;
	 	tmp = n;
	 	// f.pb(1);
	 	// if(n%2==0)f.pb(2);
	 	// while(n%2==0)n/=2;
	 	// if(n%3==0)f.pb(3);
	 	// while(n%3==0)n/=3;
	 	solve(n);
	 	// ans.pb((n*(n+1))/2);
	 	trace(f, x)
	 	{	
	 		tr = tmp/x;
	 		// debug(x, tr, (tr*(1 + 1 + (tr-1)* x)));
	 		ans.insert( (tr*(2 + (tr-1)* x))/2);
	 	}
	 	// sort(all(ans));
	 	trace(ans,x)cout<<x<<" ";
		return 0;
}