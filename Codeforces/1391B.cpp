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
const int L=1e2+7;
map<ll,ll> counter;
int visit[L][L];
int n, m;
string s[L];
int ans = 0, rx, ry, cur;
pii pr[L][L];
int children[L][L];
pii find(int x, int y)
{
	if(pr[x][y].F == x && pr[x][y].S == y)return {x,y};
	return pr[x][y] = find(pr[x][y].F,pr[x][y].S);
}
void merge(int ax, int ay, int bx, int by)
{
	pii pa = find(ax,ay);
	pii pb = find(bx,by);
	if(pa.F == pb.F && pa.S ==pb.S)return;
	if(children[pa.F][pa.S]<children[pb.F][pb.S])
	{
		children[pa.F][pa.S]+=children[pb.F][pb.S];
		pr[pb.F][pb.S] = {pa.F,pa.S};
	}
	else
	{
		children[pb.F][pb.S]+=children[pa.F][pa.S];
		pr[pa.F][pa.S] = {pb.F,pb.S};
	}
}
void dfs(int x, int y)
{
	if(x<0||y<0||x>=n||y>=m)return;
	if(visit[x][y]==cur)return;
	merge(x,y,rx,ry);
	visit[x][y] = cur;
	if(s[x][y] == 'U')dfs(x-1,y);
	if(s[x][y] == 'D')dfs(x+1,y);
	if(s[x][y] == 'L')dfs(x,y-1);
	if(s[x][y] == 'R')dfs(x,y+1);
}
void fff()
{
	cin >> n >> m;
	queue<pii>q;
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			visit[i][j] = 0;
			pr[i][j] = {i,j};
			children[i][j] = 1;
		}
		cin >> s[i];
	}
	ans = 0;
	cur = 1;
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if(!visit[i][j])
			{
				cur++;
				rx = i, ry = j;
				dfs(i,j);
			}
		}
	}
	set<pii>SET;
	FOR(i,0,n)
		FOR(j,0,m)
			SET.insert(find(i,j));
	cout << sz(SET) - 1<<ln;
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