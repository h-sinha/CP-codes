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
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=5e5+7;
std::vector<int> v[L];
int  md, tm1, arr1[L], depth1[L];
int start1[L], en1[L], en2[L];
ld co1[L];
void dfs(int vertex,int parent=-1,int dpt = 0)
{
	start1[vertex]=tm1;
	arr1[tm1]=vertex;
	tm1++;
	depth1[vertex] = dpt;
	trace(v[vertex],x)
	{
		if(x==parent)continue;
		dfs(x, vertex, (dpt+1)%md);
	}
	en1[vertex] = tm1-1;
}
std::vector<int>seg[4*L];
int size_of_base;
void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg[index].pb(depth1[arr1[start]]);
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	trace(seg[2*index],x )seg[index].pb(x);
	trace(seg[2*index+1],x )seg[index].pb(x);
	sort(all(seg[index]));
	return;
}
int query(int l, int r,int x, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return 0;
	if(start >= l && end <= r)
	{
		return upper_bound(seg[index].begin(), seg[index].end(),x)-lower_bound(seg[index].begin(), seg[index].end(),x);
	}
	int mid = (start + end)/2;
	int query_left, query_right;
	query_left = query(l, r,x, start, mid, 2*index );
	query_right = query(l, r,x, mid+1, end, 2*index + 1);
	return (query_left+ query_right);
}
int xx=1;
void fff()
{

	int x,a,b;
	ld n;
	cin >> n >> a >> b;
	tm1 = 1;
	md = a;
	FOR(i,0,n+1)
	{
		v[i].clear();
	}
	FOR(i,0,4*n)
	{
		seg[i].clear();
	}
	FOR(i,2,n+1)
	{
		cin >> x;
		v[x].pb(i);
		v[i].pb(x);
	}
	dfs(1);
	size_of_base = tm1;
	build();
	FOR(i,1,n+1)co1[i] = query(start1[i], en1[i], depth1[i]);
	tm1 = 1;
	md = b;
	dfs(1);
	FOR(i,0,4*n)
	{
		seg[i].clear();
	}
	ld co2, ans = 0;
	size_of_base = tm1;
	build();
	FOR(i,1,n+1)
	{
		co2 = query(start1[i], en1[i], depth1[i]);
		ans += (co1[i]/n + co2/n - (co1[i]*co2)/(n*n));
	}
	printf("Case #%d: %.10Lf\n",xx++,ans);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}