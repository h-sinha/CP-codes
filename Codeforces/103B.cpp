#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
int flag = -1;
set <int> v[102];
std::vector<bool> visit(102);
std::vector<bool> done(102);
void dfs(int vertex, int parent)
{
	// cout<<vertex << " - "<<visit[vertex]<<ln;
	if(visit[vertex])
	{
		flag = vertex;
		// return;
	}
	if(done[vertex])return;
	done[vertex] = 1;
	// if(flag != -1)return;
	visit[vertex] = 1;
	trace(v[vertex], x)
		if(x!=parent)
			dfs(x, vertex);
	visit[vertex] = 0;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, x, y;
	 	cin >> n >> m;
	 	FOR(i,0,m)
	 	{
	 		cin >> x >> y;
	 		v[x].insert(y);
	 		v[y].insert(x);
	 	}
	 	dfs(1,-1);
	 	// cout << flag <<ln;
	 	FOR(i,1,n+1)
	 	{
	 		if(!done[i])
	 		{
	 			flag = -1;
	 			break;
	 		}
	 	}
	 	if(flag == -1)
	 	{
	 		cout << "NO";
	 		return 0;
	 	}
	 	v[flag].clear();
	 	FOR(i,1,n+1)v[i].erase(flag);
	 	fill(all(done),0);
	 	flag = -1;
	 	FOR(i,1,n+1)
	 		if(!done[i])dfs(i,-1);
	 	if(flag == -1)cout << "FHTAGN!";
	 	else cout << "NO";
		return 0;
}}