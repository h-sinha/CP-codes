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
	ll x, y, z;
	int i;
};
bool cx(node x, node y)
{
	if(x.x == y.x)
	{
		if(x.y == y.y)return x.z < y.z;
		return x.y < y.y;
	}
	return x.x < y.x;
}
int f[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	node t;
	std::vector<node> v;
	FOR(i,0,n)
	{
		cin >> t.x >> t.y >> t.z;
		t.i = i+1;
		v.pb(t);
	}	
	sort(all(v), cx);
	std::vector<node> left;
	std::vector<pii> ans;
	FOR(i,0,sz(v))
	{
		if(i == sz(left)-1)
		{
			left.pb(v[i]);
			break;
		}
		if(v[i].x == v[i+1].x &&v[i].y == v[i+1].y)
		{
			ans.pb({v[i].i, v[i+1].i});
			f[v[i].i] = 1;
			f[v[i+1].i] = 1;
			i++;
		}
		else left.pb(v[i]);
	}
	v.clear();
	FOR(i,0,sz(left))
	{
		if(i == sz(left)-1)
		{
			v.pb(left[i]);
			break;
		}
		if(left[i].x == left[i+1].x)
		{
			ans.pb({left[i].i, left[i+1].i});
			f[left[i].i] = 1;
			f[left[i+1].i] = 1;
			i++;
		}
		else v.pb(left[i]);
	}
	std::vector<int> l;
	FOR(i,1,n+1)if(!f[i])l.pb(i);
	for (int i = 0; i < sz(v); i += 2)
	{
		ans.pb({v[i].i, v[i+1].i});
	}
	int a, b, cur = 0;
	trace(ans,x)
	{
		a = x.F, b = x.S;
		if(a==0)a = l[cur++];
		if(b==0)b = l[cur++];
		cout<<a<<" "<<b<<ln;
	}
	return 0;
}