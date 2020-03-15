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
int deg[L];
set<int>SET;
std::vector<int> v[L];
void update(int a)
{
	trace(v[a], x)
	{
		deg[x]--;
		if(deg[x] == 1)SET.insert(x);
	}
}
void ffs()
{
	int	n, a, b;
	cin >> n;
	FOR(i,0,n-1)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	FOR(i,1,n+1)
		if(deg[i] == 1)
			SET.insert(i);
	int x, cur, cur1;
	while(sz(SET))
	{
		cur = *SET.begin();
		SET.erase(SET.begin());
		cur1 = *SET.begin();
		SET.erase(SET.begin());
		cout<<"? "<<cur<<" "<<cur1<<endl;
		fflush(stdout);
		cin >> x;
		SET.insert(x);
		if(x == cur || x == cur1)
		{
			cout<<"! "<<x<<endl;
			return;
		}
		update(cur);
		update(cur1);
	}
}
int main()
{
	//int t;cin >> t;while(t--)
	ffs();
	return 0;
}