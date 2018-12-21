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

const int L=1e3+7;
std::vector<pii> leftarr;
std::vector<pii> rightarr;
std::vector<pii> up;
std::vector<pii> down;
std::vector<pii> uprightarr;
std::vector<pii> upleftarr;
std::vector<pii> downrightarr;
std::vector<pii> downleftarr;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, k, si, sj,a,b;
	 	cin >> n >> k;
	 	cin >> si >> sj;
	 	FOR(i,0,k)
	 	{
	 		cin >> a>>b;
	 		if(a == si)
	 		{
	 			if(b > sj)rightarr.pb(mp(b, a));
	 			else leftarr.pb(mp(b, a));
	 		}
	 		else if(b == sj)
	 		{
	 			if(a > si)down.pb(mp(a, b));
	 			else up.pb(mp(a, b));	
	 		}
	 		else if(a-si == b-sj && a>si && b > sj)
	 		{
	 			downrightarr.pb(mp(a, b));
	 		}
	 		else if(a-si == sj-b && a> si && b < sj)
	 		{
	 			downleftarr.pb(mp(a, b));
	 		}
	 		else if(si-a == b-sj && a < si && b > sj)
	 		{
	 			uprightarr.pb(mp(b, a));
	 		}
	 		else if(si - a == sj - b && a < si && b < sj)
	 		{
	 			upleftarr.pb(mp(a, b));
	 		}
	 	}
	 	int ans = 0;
	 	sort(all(rightarr));
	 	sort(all(leftarr));
	 	sort(all(up));
	 	sort(all(down));
	 	if(sz(rightarr))ans += (rightarr[0].F - sj - 1);
	 	else ans += (n-sj);
	 	if(sz(leftarr))ans += (sj - leftarr[sz(leftarr) - 1].F - 1);
	 	else ans += (sj - 1);
	 	if(sz(up))ans += (si - up[sz(up) - 1].F - 1);
	 	else ans += (si - 1);
	 	if(sz(down))ans += (down[0].F - si - 1);
	 	else ans += (n - si);
	 	sort(all(downrightarr));
	 	sort(all(downleftarr));
	 	sort(all(upleftarr));
	 	sort(all(uprightarr));
	 	if(sz(downrightarr))ans += (downrightarr[0].F - si - 1);
	 	else ans += min(n-si, n-sj);
	 	if(sz(downleftarr))ans += (downleftarr[0].F - si - 1);
	 	else ans += min(n - si, sj - 1);
	 	if(sz(upleftarr))ans += (si - upleftarr[sz(upleftarr) - 1].F - 1);
	 	else ans += min(si - 1, sj - 1);
	 	if(sz(uprightarr))ans += (uprightarr[0].F - sj - 1);
	 	else ans += min(si - 1, n - sj);
	 	cout<<ans;
		return 0;
}