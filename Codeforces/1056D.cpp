#include<bits/stdc++.h>
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
const int L=1e5+7;
std::vector<int> v[L];
int leaf[L];
int dfs(int vertex, int parent)
{
	trace(v[vertex], x)
	{
		if(x != parent)
			leaf[vertex] += dfs(x, vertex);
	}
	if(sz(v[vertex]) == 1 && vertex != 1)leaf[vertex] = 1;
	return leaf[vertex];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, a;
	 	cin >> n;
	 	if(n==1)
	 	{
	 		cout<<"1";
	 		return 0;
	 	}
	 	FOR(i,2,n+1)
	 	{
	 		cin >> a;
	 		v[a].pb(i);
	 		v[i].pb(a);
	 	}
	 	leaf[1] = dfs(1,-1);
		sort(leaf+1, leaf+n+1);
		FOR(i,1,n+1)cout<<leaf[i]<<" ";
		return 0;
}