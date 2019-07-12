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
std::vector<int> v[L];
int deg[L], x[L], y[L], n, m;
bool topo()
{
	int cur;
	queue<int>q;
	FOR(i,1,n+1)
		if(deg[i] == 0)
			q.push(i);
	while(!q.empty())
	{
		if(sz(q) > 1)return 0;
		cur = q.front();
		q.pop();
		trace(v[cur], x)
		{
			deg[x]--;
			if(deg[x] == 0)q.push(x);
		}
	}
	return 1;
}
bool check(int val)
{
	FOR(i,1,n+1)
	{
		v[i].clear();
		deg[i] = 0;
	}
	FOR(i,1,val+1)
	{
		deg[y[i]]++;
		v[x[i]].pb(y[i]);
	}
	return topo();
}
void ser(int l, int r)
{
	int mid;
	while(l < r - 1)
	{
		mid = (l + r)/2;
		if(check(mid))r = mid;
		else l = mid;
	}
	if(!check(r))r = l;
	if(!check(r))cout<<"-1";
	else cout<<r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	FOR(i,1,m+1)
		cin >> x[i] >> y[i];
	ser(1,m);
	return 0;
}