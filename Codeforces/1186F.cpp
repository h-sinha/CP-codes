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
set<int> v[L];
int x[L], y[L], deg[L], org[L], done[L];
int find(int a, int i)
{
	if(x[i] == a)return y[i];
	return x[i];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, a, b;
	 	cin >> n >> m;
	 	FOR(i,0,m)
	 	{
	 		cin >> a >> b;
	 		v[a].insert(i);
	 		v[b].insert(i);
	 		x[i] = a;
	 		y[i] = b;
	 		deg[a]++, deg[b]++;
	 		org[a]++, org[b]++;
	 	}
	 	int co = 0;
	 	FOR(i,0,m)
	 	{
	 		// debug(co, m - (n+m+1)/2);
	 		if(m - co <= (n+m+1)/2)break;
	 		a = x[i], b = y[i];
	 		// debug(a,b, deg[a], deg[b], (org[a]+1)/2 );
	 		if(deg[a]-1 < (org[a]+1)/2 || deg[b] - 1 < (org[b]+1)/2)continue;
	 		co++;
	 		// debug(a,find(a,i));
	 		v[a].erase(find(a,i));
	 		v[b].erase(find(b,i));
	 		deg[a]--, deg[b]--;
	 		done[i] = 1;
	 	}
	 	// debug(co);
	 	cout<<m-co<<ln;
	 	// FOR(i,1,n+1)
	 	FOR(i,0,m)
	 	{
	 		if(!done[i])cout<<x[i]<<" "<<y[i]<<ln;
	 		// trace(v[i], x)
	 		// {
	 			// if(i == min(i,x))
	 			// cout<<i<<" "<<x<<ln;
	 		// }
	 	}
		return 0;
}