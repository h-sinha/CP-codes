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
map<ll,ll> counter;
ll a[L], b[L], n;
bool check(ll k)
{
	FOR(i,0,n)b[i] = (a[i]^k);
	sort(b,b+n);
	FOR(i,0,n)
	{
		if(a[i] != b[i])
		{
			// debug(k,a[i],b[i],k);
			return 0;
		}
	}
	return 1;
}
void fff()
{
	ll xr = 0;
	cin >> n;
	FOR(i,0,n)cin >> a[i], xr^=a[i];
	sort(a,a+n);
	ll ans = LLONG_MAX;
	if(n%2==1)
	{
		cout<<-1<<ln;
		return;
	}
	else
	{
		ll aux = xr;
		xr ^= a[n-1];
		FOR(i,0,n)
		{
			if((aux^a[i]^xr)!=0&&check(aux^a[i]^xr))
			{

				ans = min(ans,(aux^a[i]^xr));
			}
		}
	}
	if(ans > 0 && ans!=LLONG_MAX)
	{
		cout<<ans<<ln;
		return;
	}
	cout<<-1<<ln;
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