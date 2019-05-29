#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

const int L=1e4+7, M = 502;
int parent_pre[L][M], parent_suf[L][M], parent_aux[M];
int children_pre[L][M], children_suf[L][M], children_aux[M];
int a[L], b[L], co[M];
int cur;
inline int find_parent_pre(int v)
{
	if(parent_pre[cur][v] == v)return v;
	return parent_pre[cur][v] = find_parent_pre(parent_pre[cur][v]);
}
inline void merge_pre(int a, int b)
{
	a = find_parent_pre(a);
	b = find_parent_pre(b);
	if(a==b)return;
	if(children_pre[cur][a] > children_pre[cur][b])
	{
		parent_pre[cur][a] = parent_pre[cur][b];
		children_pre[cur][b] += children_pre[cur][a];
	}
	else
	{
		parent_pre[cur][b] = parent_pre[cur][a];
		children_pre[cur][a] += children_pre[cur][b];
	}
}
inline int find_parent_suf(int v)
{
	if(parent_suf[cur][v] == v)return v;
	return parent_suf[cur][v] = find_parent_suf(parent_suf[cur][v]);
}
inline void merge_suf(int a, int b)
{
	a = find_parent_suf(a);
	b = find_parent_suf(b);
	if(a==b)return;
	if(children_suf[cur][a] > children_suf[cur][b])
	{
		parent_suf[cur][a] = parent_suf[cur][b];
		children_suf[cur][b] += children_suf[cur][a];
	}
	else
	{
		parent_suf[cur][b] = parent_suf[cur][a];
		children_suf[cur][a] += children_suf[cur][b];
	}
}
inline int find_parent_aux(int v)
{
	if(parent_aux[v] == v)return v;
	return parent_aux[v] = find_parent_aux(parent_aux[v]);
}
inline void merge_aux(int a, int b)
{
	a = find_parent_aux(a);
	b = find_parent_aux(b);
	if(a==b)return;
	if(children_aux[a] > children_aux[b])
	{
		parent_aux[a] = parent_aux[b];
		children_aux[b] += children_aux[a];
	}
	else
	{
		parent_aux[b] = parent_aux[a];
		children_aux[a] += children_aux[b];
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, k, l, r;
	 	cin >> n >> m;
	 	FOR(i,1,m+1)
	 		cin >> a[i] >> b[i];
	 	FOR(i,1,n+1)
	 	{
	 		parent_suf[m+1][i] = i;
	 		parent_pre[0][i] = i;
	 		children_pre[0][i] = 1;
	 		children_suf[m+1][i] = 1;
	 	}
	 	FOR(i,1,m+1)
	 	{
	 		FOR(j,1,n+1)
	 		{
	 			parent_pre[i][j] = parent_pre[i-1][j];
	 			children_pre[i][j] = children_pre[i-1][j];
	 		}
	 		cur = i;
	 		merge_pre(a[i], b[i]);
	 	}
	 	RFOR(i,m,1)
	 	{
	 		FOR(j,1,n+1)
	 		{
	 			parent_suf[i][j] = parent_suf[i+1][j];
	 			children_suf[i][j] = children_suf[i+1][j];
	 		}
	 		cur = i;
	 		merge_suf(a[i], b[i]);
	 	}
	 	cin >> k;
	 	int ans;
	 	while(k--)
	 	{
	 		cin >> l >> r;
	 		FOR(i,1,n+1)
	 		{
	 			parent_aux[i] = parent_pre[l-1][i];
	 			children_aux[i] = children_pre[l-1][i];
	 		}
	 		FOR(i,1,n+1)
	 			merge_aux(parent_suf[r+1][i], i);
	 		FOR(i,1,n+1)
	 			co[i] = 0;
	 		ans = 0;
	 		FOR(i,1,n+1)
	 			co[find_parent_aux(i)]++;
	 		FOR(i,1,n+1)
	 			if(co[i])
	 				ans++;
	 		cout<<ans<<ln;
	 	}
		return 0;
}