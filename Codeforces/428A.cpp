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
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int dp[100002],ans=0,target[100002],init[100002],parent[100002][3];
std::vector<int> v[100002];
std::vector<int> out;
void setparent(int vertex,int _parent)
{
	parent[vertex][0]=_parent;
	trace(v[vertex],x)
		if(x!=_parent)
			setparent(x,vertex);
}
void dfs(int vertex,int _parent)
{
	if(parent[vertex][1]!=-1 && dp[parent[vertex][1]]==1)init[vertex]=1-init[vertex];
	if(init[vertex]!=target[vertex])
	{
		if(parent[vertex][1]==-1 )
		{
			dp[vertex]=1;
			out.pb(vertex);
			ans++;
		}
		else 
		{
			dp[vertex]=dp[parent[vertex][1]]^1;
			out.pb(vertex);
			ans++;
		}
	}
	else if(parent[vertex][1]!=-1)dp[vertex]=dp[parent[vertex][1]];
	trace(v[vertex],x)
		if(x!=_parent)
			dfs(x,vertex);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int a,b,n;
		cin>>n;
		FOR(i,1,n)
		{
			cin>>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}
		FOR(i,1,n+1)cin>>init[i];
		FOR(i,1,n+1)cin>>target[i];
		FOR(i,1,14)FOR(j,1,2)parent[i][j]=-1;
		setparent(1,-1);
		FOR(j,1,2)FOR(i,1,n+1)if(parent[i][j-1]!=-1)parent[i][j]=parent[parent[i][j-1]][j-1];
		dfs(1,-1);
		cout<<ans<<ln;
		trace(out,x)cout<<x<<ln;
		return 0;
}