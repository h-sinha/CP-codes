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

const int L=57;
std::map<int, int> cx, cy;
int x[L], y[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	FOR(i,0,4*n+1)
	{
		cin >> x[i] >> y[i];
		cx[x[i]]++;
		cy[y[i]]++;
	}
	std::vector<int> vx, vy;
	trace(cx, x)
	{
		if(x.S >= n)vx.pb(x.F);
	}
	trace(cy, x)
	{
		if(x.S >= n)vy.pb(x.F);
	}
	sort(all(vx));
	sort(all(vy));
	FOR(i,0,sz(vx))
	{
		FOR(j,i+1,sz(vx))
		{
			FOR(k,0,sz(vy))
			{
				FOR(l,k+1,sz(vy))
				{
					int lx = min(vx[i], vx[j]);
					int rx = max(vx[i], vx[j]);
					int ly = min(vy[k], vy[l]);
					int ry = max(vy[k], vy[l]);
					std::vector<pii> ans;
					FOR(m,0,4*n+1)
					{
						if(x[m] == lx || x[m] == rx)
						{
							if(y[m]<=ry && y[m]>=ly)continue;
						}
						if(y[m] == ly || y[m] == ry)
						{
							if(x[m]<=rx && x[m]>=lx)continue;
						}
						ans.pb({x[m],y[m]});
					}
					if(sz(ans) == 1)
					{
						cout<<ans[0].F<<" "<<ans[0].S<<ln;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}