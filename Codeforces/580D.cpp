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

const int L=20;
int n, m, k;
ll a[L];
std::map<pii, ll> counter;
ll solve(ll i, ll sofar, ll done[20])
{
	if(i>n || i<1 || sofar >m)return 0;
	if(sofar == m)return a[i];
	done[i] = 1;
	ll tmp = 0, ret = 0;;
	FOR(j,1,n+1)
	{
		if(i==2 && j==7)debug(i,j,done[j]);
		// debug(j,done[j]);
		if(done[j])continue;
		if(counter.find(mp(i,j)) != counter.end())
		{
			tmp = counter[{i,j}];
		}
		else tmp = 0;
		if(i==2 && j == 7)
		debug(i,j,tmp);
		// debug(i,j,tmp,a[i],solve(j,sofar+1,done));
		ret = max(ret, solve(j,sofar+1,done) + a[i] + tmp);
	}
	done[i] = 0;
	// debug(i,ret);
	return ret;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> m >> k;
	 	ll x,y,c;
	 	FOR(i,1,n+1)
	 		cin >> a[i];
	 	FOR(i,0,k)
	 	{
	 		cin >> x >> y >> c;
	 		counter[mp(x,y)] = c;
	 	}
	 	ll done[20], ans = 0;
	 	FOR(i,2,3)
	 	{
	 		FOR(j,1,n+1)done[j] = 0;
	 		ans = max(ans, solve(i, 1, done));
	 		// cout<<ln;
	 	}
	 	cout<<ans;
		return 0;
}