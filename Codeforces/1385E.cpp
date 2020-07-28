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
std::vector<int> v[L];
int deg[L], idx[L];
void fff()
{
	int n, m, t, x, y;
	std::vector<pii> aux;
	cin >> n >> m;
	FOR(i,1,n+1)
	{
		v[i].clear();
		deg[i] = 0;
	}
	FOR(i,0,m)
	{
		cin >> t >> x >> y;
		if(t)
		{
			v[x].pb(y);
			deg[y]++;
		}
		else aux.pb({x,y});
	}
	int co = 0;
	queue<int>q;
	FOR(i,1,n+1)
		if(!deg[i])
			q.push(i);
	while(!q.empty())
	{
		x = q.front();
		idx[x] = co++;
		q.pop();
		trace(v[x], y)
		{
			deg[y]--;
			if(!deg[y])q.push(y);
		}
	}
	if(co < n)
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	FOR(i,1,n+1)
		trace(v[i],x)
			cout << i <<" "<<x<<ln;	
	trace(aux,x)
	{
		if(idx[x.F]<idx[x.S])cout << x.F <<" "<<x.S<<ln;
		else cout << x.S<<" "<<x.F<<ln;
	}
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