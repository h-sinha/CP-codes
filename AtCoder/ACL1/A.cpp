#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
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
typedef	priority_queue<pii, std::vector<pii>, greater<pii> > revpr;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L = 1e6 + 7;
ll x[L], y[L], idx[L];
bool comp(int a, int b)
{
	return x[a] < x[b];
}
int children[L], parent[L];
int component(int x)
{
	if (parent[x] == x)return x;
	return parent[x] = component(parent[x]);
}
void merge(int a, int b)
{
	int pa = component(a);
	int pb = component(b);
	if (pa == pb)return;
	if (children[pa] > children[pb])
	{
		children[pb] += children[pa];
		parent[pa] = pb;
	}
	else
	{
		children[pa] += children[pb];
		parent[pb] = pa;
	}
	return;
}
void fff()
{
	ll n;
	cin >> n;
	pbds prv, nxt;
	std::vector<int> v;
	FOR(i, 0, n)
	{
		parent[i] = i;
		children[i] = 1;
		cin >> x[i] >> y[i];
		idx[y[i]] = i;
		v.pb(i);
	}
	sort(all(v), comp);
	trace(v, i)
	{
		nxt.insert(y[i]);
	}
	int x;
	int co = 0, tmp;
	trace(v, i)
	{
		co = 0;
		nxt.erase(y[i]);
		x = nxt.order_of_key(y[i]);
		if (sz(nxt) == x)continue;
		tmp = *nxt.find_by_order(x);
		merge(i, idx[tmp]);
		while (co < 10)
		{
			x++;
			co++;
			if (sz(nxt) == x)break;
			tmp = *nxt.find_by_order(x);
			merge(i, idx[tmp]);
		}
	}
	reverse(all(v));
	trace(v, i)
	{
		nxt.insert(y[i]);
	}
	trace(v, i)
	{
		co = 0;
		nxt.erase(y[i]);
		x = nxt.order_of_key(y[i]);
		if (x == 0)continue;
		tmp = *nxt.find_by_order(x - 1);
		merge(i, idx[tmp]);
		// debug(i,idx[tmp]);
		while (co < 10)
		{
			x--;
			co++;
			if (x <= 0)break;
			tmp = *nxt.find_by_order(x - 1);
			merge(i, idx[tmp]);
		}
	}
	FOR(i, 0, n)cout << children[component(i)] << ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}