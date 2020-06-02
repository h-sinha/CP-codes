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
const int L=1e3+7;
string s[L][11];
ll d[L][L], n, m, k, w;
struct node
{
	ll w;
	int a,b;
};
ll compute(string s1[L], string s2[L])
{
	ll co = 0;
	FOR(i,0,n)
		FOR(j,0,m)
			co += (s1[i][j] != s2[i][j]);
	return co*w;
}
bool comp(node x, node y)
{
	return x.w < y.w;
}
int children[L], parent[L], done[L];
int component(int x)
{
	if(parent[x] == x)return x;
	return parent[x] = component(parent[x]);
}
void merge(int a, int b)
{
	int pa = component(a);
	int pb = component(b);
	if(children[pa] > children[pb])
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
int dd[L], pr[L];
std::vector<int> aux[L];
void fff()
{
	cin >> n >> m >> k >> w;
	FOR(i,0,k+1)FOR(j,0,k+1)d[i][j] = INT_MAX;
	ll tot = 0;
	std::vector<node> edge;
	FOR(i,1,k+1)
	{
		parent[i] = i;
		FOR(j,0,n)
			cin >> s[i][j];
		FOR(j,1,i)
		{
			d[i][j] = d[j][i] = compute(s[i],s[j]);
			edge.pb(node{d[i][j],i,j});
		}
	}
	sort(all(edge), comp);
	ll ans = 0;
	trace(edge, x)
	{
		if(component(x.a) == component(x.b))continue;
		if(x.w >= n*m)break;
		merge(x.a,x.b);
		aux[x.a].pb(x.b);
		aux[x.b].pb(x.a);
		done[x.a] = 1, done[x.b] = 1;
		ans += x.w;
	}
	std::vector<pii> out;
	int f = 0;
	FOR(i,1,k+1)
	{
		if(!done[i])
		{
			ans += (n*m);
			aux[0].pb(i);
		}
		else
		{
			f = component(i);
			if(f == i)
			{
				ans += (n*m);
				aux[0].pb(i);
			}
		}
	}
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		f = q.front();
		q.pop();
		if(dd[f])continue;
		dd[f] = 1;
		trace(aux[f],x)
		{
			if(dd[x])continue;
			out.pb({x,f});
			q.push(x);
		}
	}
	cout<<ans<<ln;
	trace(out,x)cout<<x.F<<" "<<x.S<<ln;
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