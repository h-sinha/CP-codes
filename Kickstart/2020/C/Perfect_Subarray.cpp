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
const int L=1e5+7;
const int M=1e7+7;
std::vector<int> v;
void pre()
{
	int x = 0;
	while(x*x<=1e7)
	{
		v.pb(x*x);
		x++;
	}
}
int xx = 0;
ll a[L];
int co[2*M],au=1e7;
void fff()
{
	xx++;
	ll ans = 0;
	int n;
	cin >> n;
	FOR(i,0,n)cin >> a[i];
	std::vector<int> aux;
	aux.pb(a[0]+au);
	co[a[0]+au]++;
	ll mx = a[0];
	FOR(i,1,n)
	{
		a[i] += a[i-1];
		aux.pb(a[i]+au);
		co[a[i]+au]++;
		mx = max(mx,a[i]);
	}
	trace(v,x)ans += co[x+au];
	FOR(i,0,n)
	{
		co[a[i]+au]--;
		trace(v,x)
		{
			if(a[i]+x>mx)break;
			ans += co[a[i]+x+au];
		}
	}
	trace(aux,x)co[x] = 0;
	cout<<"Case #"<<xx<<": "<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;cin >> t;while(t--)
	fff();
	return 0;
}