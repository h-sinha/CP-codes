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
#define pii pair<int,int>
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
int co[L], a[L], f[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int q, n, ff;
		cin >> q;
		std::vector<pii> v;
		while(q--)
		{
			cin >>n;
			v.clear();
			FOR(i,1,n+1)co[i] = 0, f[i] = 0;
			FOR(i,0,n)
			{
				cin >> a[i] >> ff;
				co[a[i]]++;
				if(ff)
				f[a[i]]++;
			}
			FOR(i,1,n+1)
			{
				if(co[i] > 0)v.pb(mp(co[i], f[i]));
			}
			sort(all(v));
			int cur,tt,ans = 0, prev, tot = 0;
			prev = v[sz(v)-1].F+1;
			int j, mx = -1,idx;
			RFOR(i,sz(v)-1, 0)
			{
				if(v[i].F < prev - 1)
					prev = v[i].F + 1;
				mx = min(v[i].S,prev-1);
				j = i;
				idx = i;
				while(j>=0 && v[j].F>=prev-1)
				{
					if(mx>min(v[j].S,prev-1))idx = j;
					mx = max(mx,min(v[j].S,prev-1));
					j--;
				}
				ans += (prev-1);
				prev--;
				tot += mx; 
				i = idx;
				if(prev == 0)break;
			}
			cout<<ans<<" "<<tot<<ln;
		}
		return 0;
}