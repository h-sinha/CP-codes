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
const int L=1e6+7;
int last_visit[L];
int bit[L], ans[L], a[L];
struct Query 
{ 
	int l, r, idx; 
}; 
bool cmp(Query x, Query y) 
{ 
	return x.r < y.r; 
} 
void update(int idx, int val, int bit[], int n) 
{ 
	for (; idx <= n; idx += idx&-idx) 
		bit[idx] += val; 
} 
int query(int idx, int bit[], int n) 
{ 
	int sum = 0; 
	for (; idx>0; idx-=idx&-idx) 
		sum += bit[idx]; 
	return sum; 
} 
ll n, q;
Query queries[L];
void answeringQueries() 
{ 
	init(last_visit, -1);
	int query_counter = 0; 
	for (int i=0; i<n; i++) 
	{ 
		if (last_visit[a[i]] !=-1) 
			update (last_visit[a[i]] + 1, -1, bit, n); 
		last_visit[a[i]] = i; 
		update(i + 1, 1, bit, n); 
		while (query_counter < q && queries[query_counter].r == i) 
		{ 
			ans[queries[query_counter].idx] = 
					query(queries[query_counter].r + 1, bit, n)- 
					query(queries[query_counter].l, bit, n); 
			query_counter++; 
		} 
	} 
	for (int i=0; i<q; i++) 
		cout << ans[i] << endl; 
} 
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	FOR(i,0,n)cin >> a[i];
	FOR(i,0,q)
	{
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].idx= i;
	}
	sort(queries, queries+q, cmp); 
	answeringQueries(); 
	return 0; 
} 