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
std::vector<pii> v;
std::vector<ll> pre;
ll n,m,q,co[L], out[L];
struct query
{
	ll r,idx,i;
};
bool comp(query x, query y)
{
	return x.r < y.r;
}
std::vector<query> ans;
void solve(ll k, int q)
{
	std::vector<ll> ::iterator it;
	it = lower_bound(all(pre), k);
	if(it == pre.end())
	{
		k-=pre[m-1];
		k--;
		k%=m;
		ans.pb(query{m-1,k,q}); 
		return;
	}
	if(it == pre.begin())
	{
		ans.pb(query{0,1,q}); 
		return;
	}
	it--;
	k-=(*it);
	k--;
	int cur = it-pre.begin();
	cur++;
	k%=cur;
	ans.pb(query{cur-1,k,q}); 
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a, sofar = 0;
	 	ll k;
	 	cin >> n >> m >> q;
	 	FOR(i,0,n)
	 	{
	 		cin >> a;
	 		co[a]++;
	 	}
	 	FOR(i,1,m+1)v.pb(mp(co[i], i));
	 	sort(all(v));
	 	pre.resize(m);
	 	FOR(i,1,m)
	 	{
	 		pre[i] = ((v[i].F - v[i-1].F)*i);
	 		pre[i] += pre[i-1];
	 	}
	 	FOR(i,0,q)
	 	{
	 		cin >> k;
	 		k-=n;
	 		solve(k,i);
	 	}
	 	sort(all(ans), comp);
	 	int cur = 0;
	 	pbds SET;
	 	FOR(i,0,m)
	 	{
	 		SET.insert(v[i].S);
	 		while(cur<sz(ans) && ans[cur].r<=i)
	 		{
	 			out[ans[cur].i] = (*SET.find_by_order(ans[cur].idx));
	 			cur++;
	 		}
	 	}
	 	FOR(i,0,q)cout<<out[i]<<ln;
		return 0;
}