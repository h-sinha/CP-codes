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
set<int>done, rem;
stack<int>instack;
std::vector<int> visit(L), v[L];
int f = 0, n, m;
void dfs(int vertex)
{
	if(f)return;
	if(sz(rem) >= (n+3)/4 && sz(done) >= (n+3)/4)
	{
		cout << "PAIRING\n";
		int cur = min(sz(rem), sz(done));
		cout << cur << ln;
		while(cur--)
		{
			cout << *rem.begin() <<" "<<*done.begin()<<ln;
			rem.erase(rem.begin());
			done.erase(done.begin());
		}
		f = 1;
		return;
	}
	rem.erase(vertex);
	instack.push(vertex);
	if(sz(instack) >= (n+1)/2)
	{
		cout << "PATH\n";
		cout << sz(instack) << ln;
		while(!instack.empty())
		{
			cout << instack.top() << " ";
			instack.pop();
		}
		cout << ln;
		f = 1;
		return;
	}
	visit[vertex] = 1;
	trace(v[vertex], x)
	{
		if(!visit[x])dfs(x);
	}
	if(f)return;
	instack.pop();
	done.insert(vertex);
}
void fff()
{
	int a, b;
	cin >> n >> m;
	f = 0;
	rem.clear(), done.clear();
	while(!instack.empty())instack.pop();
	FOR(i,1,n+1)
	{
		v[i].clear();
		visit[i] = 0;
		rem.insert(i);
	}
	FOR(i,0,m)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	FOR(i,1,n+1)
	{
		if(!visit[i])
		{
			dfs(i);
		}
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