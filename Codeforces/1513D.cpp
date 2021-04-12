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
#define eb emplace_back
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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const ll L=1e6+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll a[L], visit[L];
ll children[L], parent[L];
ll component(ll x)
{
	if(parent[x] == x)return x;
	return parent[x] = component(parent[x]);
}
bool merge(ll a, ll b)
{
	ll pa = component(a);
	ll pb = component(b);
	if(pa == pb)return 0;
	if(children[pa] > children[pb])
	{
		children[pb] += children[pa];
		parent[pa] = pb;
	}
	else
	{
		children[pa] += children[pb];
		parent[pb] = pa;
	}
	return 1;
}
void fff()
{
	ll n, p;
	cin >> n >> p;
	FOR(i,1,n+1)
	{
		cin >> a[i];
		parent[i] = i;
		children[i] = 1;
		visit[i] = 0;
	}
    std::vector<pii> v;
    FOR(i,1,n+1)v.pb({a[i], i});
    sort(all(v));
    ll l, r,i, ans = 0, g, ret;
    trace(v,x)
    {
    	i = x.S;
    	if(a[i] >= p)break;
    	FOR(j,i+1,n+1)
    	{
    		if(a[j]%a[i])break;
    		if(visit[j])
    		{
    			ret = merge(i,j);
    			if(ret)ans += a[i];
    			break;
    		}
    		ret = merge(i,j);
    		visit[j] = 1;
    		if(ret)ans += a[i];
    	}
    	RFOR(j,i-1,1)
    	{
    		if(a[j]%a[i])break;
    		if(visit[j])
    		{
    			ret = merge(i,j);
    			if(ret)ans += a[i];
    			break;
    		}
    		ret = merge(i,j);
    		visit[j] = 1;
    		if(ret)ans += a[i];
    	}
    }
    FOR(i,2,n+1)
    {
    	ret = merge(i, i-1);
    	if(!ret)continue;
    	ans += p;
    }
    cout << ans << ln;
}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}