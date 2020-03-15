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
std::vector<int> v[L], rv[L];
set<int> nxt[L];
int n, m, d[L], visit[L], s, t, p[L];
void bfs()
{
	revpr q;
	pii cur;
	q.push({0,t});
	init(d, 1000000);
	d[t] = 0;
	while(!q.empty())
	{
		cur = q.top();
		q.pop();
		trace(rv[cur.S], x)
		{
			if(d[x] > d[cur.S] + 1)
			{
				d[x] = d[cur.S] + 1;
				q.push({d[x],x});
			}
		}
	}
}
void ffs()
{
	int a, b, k;
	cin >> n >> m;
	FOR(i,0,m)
	{
		cin >> a >> b;
		v[a].pb(b);
		rv[b].pb(a);
	}
	cin >> k;
	FOR(i,0,k)cin >> p[i];
	s = p[0], t = p[k-1];
	bfs();
	FOR(i,1,n+1)
	{
		trace(v[i], x)
		{
			if(d[x] == d[i] - 1)nxt[i].insert(x);
		}
	}
	int mx = 0, mn = 0;
	int x;
	FOR(i,0,k-1)
	{
		x = p[i];
		if(nxt[x].find(p[i+1]) != nxt[x].end())
		{
			if(sz(nxt[x]) > 1)
				mx++;
		}
		else mn++, mx++;
	}
	cout<<mn<<" "<<mx<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	ffs();
	return 0;
}