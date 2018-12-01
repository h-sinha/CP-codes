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
const int L=50002;
std::vector<int> v[L];
int ans=0,dp[L][502],k;
void dfs(int vertex,int parent)
{
	dp[vertex][0] = 1;
	trace(v[vertex],x)
	{
		if(x==parent)continue;
		dfs(x,vertex);
		FOR(i,0,k)
			ans += dp[vertex][i]*dp[x][k-i-1];
		FOR(i,1,k)dp[vertex][i]+= dp[x][i-1];
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,a, b;
	 	cin >> n >> k;
	 	FOR(i,0,n-1)
	 	{
	 		cin >> a >> b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	dfs(1,-1);
		cout<<ans;
		return 0;
}