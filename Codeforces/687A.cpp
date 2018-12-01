#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
std::vector<int> v[100002];
std::vector<bool> visit(100002);
std::vector<int> col[2];
int flag=0,colour[100002];
void dfs(int vertex,int cur)
{
	if(visit[vertex])
	{
		if(colour[vertex]!=cur)flag=1;
		return;
	}
	visit[vertex]=1;
	col[cur].pb(vertex);
	colour[vertex]=cur;
	trace(v[vertex],x)
		dfs(x,1-cur);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int a,b,n,m;
		cin>>n>>m;
		FOR(i,0,m)
		{
			cin>>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}
		FOR(i,1,n+1)
		{
			if(!visit[i] && sz(v[i]))
				dfs(i,0);
		}
		if(flag){cout<<"-1";return 0;}
		cout<<sz(col[0])<<ln;
		trace(col[0],x)cout<<x<<" ";
		cout<<ln;
		cout<<sz(col[1])<<ln;
		trace(col[1],x)cout<<x<<" ";
		cout<<ln;
		return 0;
}