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

const int L=2e5+7;
std::vector<int> fact[L];
int done[L], p[L], c[L];
void pre()
{
	int tmp;
	FOR(i,1,200001)
	{
		tmp = sqrt(i) + 1;
		FOR(j,1,tmp)
		{
			if(i%j == 0)
			{
				fact[i].pb(j);
				if(i != j*j)fact[i].pb(i/j);
			}
		}
		sort(all(fact[i]));
	}
}
bool check(std::vector<int> &v, int x)
{
	int cur, m = sz(v), col, f;
	std::vector<bool> aux(m);
	FOR(i,0,sz(v))
	{
		if(aux[i])continue;
		cur = i, col = v[i], f = 0;
		while(!aux[cur])
		{
			if(col != v[cur])f = 1;
			aux[cur] = 1;
			cur = (cur+x)%m;
		}
		if(!f)return 1;
	}
	return 0;
}
int cycle(int x)
{
	std::vector<int> v;
	while(!done[x])
	{
		v.pb(c[x]);
		done[x] = 1;
		x = p[x];
	}
	int cur = sz(v), ret = sz(v);
	trace(fact[cur], y)
	{
		if(check(v, y))return y;
	}
	return ret;
}
void ffs()
{
	int n;
	cin >> n;
	FOR(i,0,n)
	{
		done[i] = 0;
		cin >> p[i];
		p[i]--;
	}
	FOR(i,0,n)
		cin >> c[i];
	int ans = n;
	FOR(i,0,n)
	{
		if(!done[i])
		{
			ans = min(cycle(i), ans);
		}
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;cin >> t;while(t--)
	ffs();
	return 0;
}