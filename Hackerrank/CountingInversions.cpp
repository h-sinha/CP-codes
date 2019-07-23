#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif
template <typename X> ostream& operator << (ostream& x,const vector<X>& v){for(int i=0;i<v.size();++i) x<<v[i]<<" ";return x;} 
template <typename X> ostream& operator << (ostream& x,const set<X>& v){for(auto it:v) x<<it<<" ";return x;} 
template <typename X, typename Y> ostream& operator << (ostream& x, const pair<X,Y>& v) {x<<v.first<<" => "<<v.second<<"\n";return x;} 
template <typename T, typename S> ostream& operator << (ostream& os, const map<T, S>& v) { for (auto it : v) os << it.first << " => " << it.second << endl; return os; }
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

const int L=1e5+7;
int a[L];
ll ans = 0;
void merge(int l, int r, int mid)
{
	int na[L];
	int i1 = l, i2 = mid + 1, id = 0;
	while(i1<=mid && i2<=r)
	{
		if(a[i1] <= a[i2])
		{
			na[id++] = a[i1++];
		}
		else
		{
			na[id++] = a[i2++];
			ans += (mid - i1 + 1);
		}
	}
	while(i1 <= mid)na[id++] = a[i1++];
	while(i2 <= r)na[id++] = a[i2++];
	FOR(i,0,id)a[l+i] = na[i];
}
void solve(int l, int r)
{
	if(l == r)return;
	int mid = (l + r)/2;
	solve(l, mid);
	solve(mid + 1, r);
	merge(l, r, mid);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		FOR(i,0,n)cin >> a[i];
		solve(0,n-1);
		cout<<ans<<ln;
	}
	return 0;
}