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
	ll x, y, z, w;	
};
struct node1
{
	ll d, i, j;	
};
int f[L];
std::vector<node> v;
ll calc(int i, int j)
{
	ll x = v[i].x - v[j].x;
	x*=x;
	ll y = (v[i].y - v[j].y);
	y*=y;
	ll z = (v[i].z - v[j].z);
	z*=z;
	return x + y + z;
}
bool comp(node1 x, node1 y)
{
	return x.d < y.d;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll a,b ,c;
	FOR(i,0,n)
	{
		cin >> a >> b >> c;
		v.pb({a,b,c,i+1});
	}
	ll val;
	std::vector<node1> vv;
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			if(i==j)continue;
			val = calc(i,j);
			vv.pb({val,i+1,j+1});
		}
	}
	sort(all(vv), comp);
	trace(vv,x)
	{
		if(f[x.i] || f[x.j])continue;
		cout<<x.i<<" "<<x.j<<ln;
		f[x.i] = 1;		
		f[x.j] = 1;		
	}
	return 0;
}