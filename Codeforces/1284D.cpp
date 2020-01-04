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
struct node
{
	int t, s, e, f;
};
bool comp(node x, node y)
{
	if(x.t == y.t)return x.f < y.f;
	return x.t < y.t;
}
int n, s[L][2], e[L][2];
bool solve(int a, int b)
{
	std::vector<node> v;
	FOR(i,0,n)
	{
		v.pb(node{s[i][a], s[i][b], e[i][b], 1});
		v.pb(node{e[i][a] + 1, s[i][b], e[i][b], 0});
	}
	multiset<int>st, en;
	sort(all(v), comp);
	int mnen, mxst;
	trace(v, x)
	{
		if(x.f)
		{
			if(!st.empty())
			{
				mnen = *en.begin();
				mxst = *st.rbegin();
				if(mnen < x.s || mxst > x.e)return 0;
				// debug(mnen, mxst, x.s, x.f);
			}
			st.insert(x.s);
			en.insert(x.e);
		}
		else
		{
			st.erase(st.find(x.s));
			en.erase(en.find(x.e));
		}
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	FOR(i,0,n)cin >> s[i][0] >> e[i][0] >> s[i][1] >> e[i][1];
	int f = solve(1, 0);
	f *= solve(0, 1);
	if(f)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}