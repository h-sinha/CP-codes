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
ll h[L], co[L];
char c[L];
std::vector<int> v[L][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, tt = 1, dist;
	cin >> t;
	ll n, g, m;
	while(t--)
	{
		cin >> n >> g >> m;
		FOR(i,0,n)
		{
			v[i][0].clear();
			v[i][1].clear();
		}
		FOR(i,0,g)
		{
			co[i] = 0;
			cin >> h[i] >> c[i];
			h[i]--;
			if(c[i] == 'C')
			v[h[i]][0].pb(i);
			else
			v[h[i]][1].pb(i);
		}
		cout <<"Case #"<<tt<<": ";
		if(m==0)
		{
			FOR(i,0,g)cout<<1<<" ";
			cout<<ln;
			tt++;
			continue;

		}
		FOR(i,0,n)
		{
			int cur = m, id, id1, f = 0;
			while(cur >=0)
			{
				dist = cur%n;
				id = (i-dist+n)%n;
				id1 = (i+dist)%n;
				// debug(i,cur, id, id1);
				if(sz(v[id][0]))
				{
					trace(v[id][0], x)
					{
						// debug(i,cur,id, 0,x);
						co[x]++;
					}
					f = 1;
				}
				if(sz(v[id1][1]))
				{
					trace(v[id1][1], x)
					{
						// debug(i,cur,id, 1,x);
						co[x]++;
					}
					f = 1;
				}
				if(f)break;
				cur--;
			}
		}
		tt++;
		FOR(i,0,g)cout<<co[i]<<" ";
		cout<<ln;
	}
	return 0;
}