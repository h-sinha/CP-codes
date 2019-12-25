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
ll x[L], y[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,sx,sy,xx,yy;
	cin >> n >> sx >> sy;
	FOR(i,0,n)
	{
		cin >> x[i] >> y[i];
	}
	std::vector<pii> ans;
	int cc = 0;
	if(sx != 0)ans.pb({sx-1,sy}),cc++;
	if(sx != 1e9)ans.pb({sx+1,sy}),cc++;
	if(sy != 1e9)ans.pb({sx,sy+1});
	if(sy != 0)ans.pb({sx,sy-1});
	int mx = -1,co = -1,idx = -1;
	FOR(i,0,cc)
	{
		co = 0;
		FOR(j,0,n)
		{
			if(ans[i].F < sx && x[j] <= ans[i].F)co++;
			if(ans[i].F > sx && x[j] >= ans[i].F)co++;
		}
		if(co > mx)
		{
			mx = co;
			idx = i;
		}
	}
	FOR(i,cc,sz(ans))
	{
		co = 0;
		FOR(j,0,n)
		{
			if(ans[i].S < sy && y[j] <= ans[i].S)co++;
			if(ans[i].S > sy && y[j] >= ans[i].S)co++;
		}
		if(co > mx)
		{
			mx = co;
			idx = i;
		}
	}
	cout<<mx<<ln;
	cout<<ans[idx].F<<" "<<ans[idx].S<<ln;
	return 0;
}